#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // For the sleep() function

// 1. The Shared Data and Synchronization Tools
pthread_mutex_t coffee_lock;
pthread_cond_t  coffee_cond;
int coffee_ready = 0; // 0 = not ready, 1 = ready

// --- THREAD 1: The Customer (The Waiter) ---
void* customer(void* arg) {
    printf("Customer: I'd like a coffee, please. Waiting at the counter...\n");

    // Lock the shared space to check the coffee status
    pthread_mutex_lock(&coffee_lock);
    
    // THE GOLDEN RULE: Always check your condition inside a while loop!
    while (coffee_ready == 0) {
        // We go to sleep here. 
        // MAGIC TRICK: This automatically unlocks the mutex while we sleep, 
        // so the barista can use it. It re-locks automatically when we wake up.
        pthread_cond_wait(&coffee_cond, &coffee_lock);
    }
    
    // If we reach this line, coffee_ready is 1, and we hold the lock again.
    printf("Customer: Ah, my coffee is ready! Drinking it now.\n");
    
    pthread_mutex_unlock(&coffee_lock);
    return NULL;
}

// --- THREAD 2: The Barista (The Signaler) ---
void* barista(void* arg) {
    printf("Barista: Starting to brew the coffee...\n");
    sleep(3); // Simulate taking 3 seconds to make coffee
    
    // Lock the shared space to update the coffee status
    pthread_mutex_lock(&coffee_lock);
    
    coffee_ready = 1; // Update the actual variable
    printf("Barista: Coffee is done! Ringing the bell...\n");
    
    // Fire the signal to wake up exactly one waiting thread
    pthread_cond_signal(&coffee_cond); 
    
    // Unlock so the customer can actually grab the coffee
    pthread_mutex_unlock(&coffee_lock);
    
    return NULL;
}

int main() {
    pthread_t cust_thread, barista_thread;

    // 2. Initialize the Mutex and Condition Variable
    pthread_mutex_init(&coffee_lock, NULL);
    pthread_cond_init(&coffee_cond, NULL);

    // 3. Start the customer thread first, so they are definitely waiting
    pthread_create(&cust_thread, NULL, customer, NULL);
    sleep(1); // Small delay just to ensure the customer gets to the counter first
    
    // Start the barista thread
    pthread_create(&barista_thread, NULL, barista, NULL);

    // Wait for both to finish their jobs
    pthread_join(cust_thread, NULL);
    pthread_join(barista_thread, NULL);

    // 4. Clean up the tools
    pthread_mutex_destroy(&coffee_lock);
    pthread_cond_destroy(&coffee_cond);

    return 0;
}