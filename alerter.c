#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if (celcius > 1000 && celcius < 0)
       return 500;
     else 
       return 200;
}

int networkAlert(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return 0;
}


void alertInCelcius(float farenheit, int (*networkerAlert)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkerAlert(celcius);

    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
     }
}

int main() {
    int (*networkerAlert)(float) = &networkAlertStub;
    alertInCelcius(400.5, networkerAlert);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6, networkerAlert);
    assert(alertFailureCount == 0);
    alertInCelcius(1900.0, networkerAlert);
    assert(alertFailureCount == 1);
    alertInCelcius(0, networkerAlert);
    assert(alertFailureCount == 2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
