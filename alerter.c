#include <stdio.h>
#include <assert.h>

//Use this macro to distiguish code for production and test environment
#define TEST_ENVIRONMENT 1

int alertFailureCount = 0;

#ifdef TEST_ENVIRONMENT 
    int networkAlertStub(float celcius) {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        // Return 200 for ok
        // Return 500 for not-ok
        // stub always succeeds and returns 200
        if (celcius > 1000 || celcius < 0)
            return 500;
        else 
            return 200;
    }
#endif

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    #ifdef TEST_ENVIRONMENT
        int returnCode = networkAlertStub(celcius);
    endif 
          //Call actual networkAlert function
        
     if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
        //use assert functions only in test environment
        assert(alertFailureCount == 0);
     }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(1900.0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
