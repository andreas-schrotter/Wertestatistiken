#include <stdio.h> 
#include <math.h> 

int main() {
    int n;
    float* numbers;
    float swap;
    float average = 0;
    float standardDeviation = 0;


    // Eingabe Elementenanzahl (nur Zahlen > 0) 
    do
    {
        printf("Wie viele Zahlen moechten Sie speichern: ");
        scanf_s("%d", &n);
    } while (n < 1);

    numbers = new float[n];


    // Einlesen der Elemente 
    printf("Bitte geben Sie nun %d Zahlen ein. \nJede Zahl muss bitte einzeln mit Enter bestaetigt werden!\n", n);

    for (int i = 0; i < n; i++) {
        scanf_s("%f", &numbers[i]);
    }


    // Sortieren der Elemente (nach selection sort) 
    // -> MIn & Max befinden sichd dadurch an den beiden Enden 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (numbers[i] > numbers[j]) {
                swap = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = swap;
            }
        }
    }


    // Berechnung vom Mittelwert 
    for (int i = 0; i < n; i++) {
        average += numbers[i];
    }

    average /= n;


    // Berechnung der Standardabweichung 
    for (int i = 0; i < n; i++) {
        standardDeviation += pow((numbers[i] - average), 2);
    }

    standardDeviation /= n;
    standardDeviation = sqrt(standardDeviation);


    // Ausgabe der Ergebnisse 
    printf("\nErgebnisse \n====================== \n");

    printf("Min: %.2f \n", numbers[0]);
    printf("Max: %.2f \n", numbers[n - 1]);
    printf("Mittelwert: %.4f \n", average);
    printf("Standardabweichung: %.4f \n", standardDeviation);

    return 0;
}