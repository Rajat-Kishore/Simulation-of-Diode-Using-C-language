#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void silicon_diode_foeward()
{ // Variable declaration
    FILE *ptr = NULL;
    float q, k, T, V_t, I_s, I_knee_threshold, knee_v;

    // constants
    q = 1.6 * pow(10, -19);  // Electron charge (C)
    k = 1.38e-23;            // Boltzmann constant (J/K)
    T = 298;                 // Room temperature (K)
    V_t = (k * T) / q;       // Thermal voltage (V)
    I_s = 1e-12;             // Reverse saturation current (A)
    I_knee_threshold = 1e-3; //  Knee current threshold  0.1 mA (A)
    knee_v = -1;

    // opening file
    ptr = fopen("Result(forward).txt", "w");

    fprintf(ptr, "This is the result output of the SILICON (PN-Junction) DIODE:\nThese are the results of the behavior of the SILICON DIODE in forward bias.\n\n🢧 We are using  Shockley diode equation mathematically describes how the current I through a PN junction diode depends on the applied voltage V across it.");
    fprintf(ptr, "\n\nThe voltage is Input Voltage and the output is in the current");
    fprintf(ptr, "\n\tVoltage (Volt) \t Current (Amp)\n");
    for (float V = 0.0; V <= 1.0; V += 0.1)
    {
        double I = I_s * (exp(V / V_t) - 1);

        if (I >= I_knee_threshold && knee_v == -1.0)
        {
            knee_v = V;
        }
        fprintf(ptr, "\t%.2f 		 		    %.2e\n", V, I);
    }

    if (knee_v != -1.0)
    {
        fprintf(ptr, "\nKnee Voltage: %.2f V (0.6 < knee voltage >= 0.7)\n", knee_v);
    }
    else
    {
        fprintf(ptr, "Knee voltage doesn't exist in this range");
    }
    fclose(ptr);
}

void silicon_diode_reverse()
{ // Variable declaration
    FILE *ptr = NULL;
    float q, k, T, V_t, I_s, I_knee_threshold, breakdown;

    // constants
    q = 1.6 * pow(10, -19); // Electron charge (C)
    k = 1.38e-23;           // Boltzmann constant (J/K)
    T = 298;                // Room temperature (K)
    V_t = (k * T) / q;      // Thermal voltage (V)
    I_s = 1e-12;            // Reverse saturation current (A)
    breakdown = 0;
    double V_b = -50; // we know it from physical tests

    // opening file
    ptr = fopen("Result(reverse).txt", "w");

    fprintf(ptr, "This is the result output of the SILICON (PN-Junction) DIODE:\nThese are the results of the behavior of the SILICON DIODE in reverse bias.\n\nTHEORY:\n🢧 We are using  Shockley diode equation mathematically describes how the current I through a PN junction diode depends on the applied voltage V across it.");
    fprintf(ptr, " \n🢧 Leakage current in a PN junction diode is the small reverse current that flows due to the movement of minority carriers when the diode is reverse biased. It remains nearly constant until the breakdown voltage is reached.");
    fprintf(ptr, "\n\nThe voltage is Input Voltage and the output is in the current");
    fprintf(ptr, "\n\tVoltage (Volt) \t Current (Amp)\n");

    for (float V = 0.0; V >= -60.0; V -= 5.0)
    {
        double I = -I_s;

        fprintf(ptr, "\t%.2f 		 		    %.2e\n", V, I);

        if (fabs(V) == fabs(V_b))
        {
            breakdown = V;
            fprintf(ptr, "\t%.2f 		 		   <<%.2e\n", V - 5, I + I);
            break;
        }
    }
    fprintf(ptr, "\n\nBreakdown occurred at %.2f V\n", breakdown);

    fclose(ptr);
}

void Ge_diode_forward()
{ // Variable declaration
    FILE *ptr = NULL;
    float q, k, T, V_t, I_s, I_knee_threshold, knee_v;

    // constants
    q = 1.6 * pow(10, -19);  // Electron charge (C)
    k = 1.38e-23;            // Boltzmann constant (J/K)
    T = 298;                 // Room temperature (K)
    V_t = (k * T) / q;       // Thermal voltage (V)
    I_s = 1e-9;              // Reverse saturation current (A)
    I_knee_threshold = 1e-3; //  Knee current threshold  0.1 mA (A)
    knee_v = -1;

    // opening file
    ptr = fopen("Result(Ge-forward).txt", "w");

    fprintf(ptr, "This is the result output of the Germanium (PN-Junction) DIODE:\nThese are the results of the behavior of the Germanium DIODE in forward bias.\n\n🢧 We are using  Shockley diode equation mathematically describes how the current I through a PN junction diode depends on the applied voltage V across it.");
    fprintf(ptr, "\n\nThe voltage is Input Voltage and the output is in the current");
    fprintf(ptr, "\n\tVoltage (Volt) \t Current (Amp)\n");
    for (float V = 0.0; V <= 1.0; V += 0.1)
    {
        double I = I_s * (exp(V / V_t) - 1);

        if (I >= I_knee_threshold && knee_v == -1.0)
        {
            knee_v = V;
        }
        fprintf(ptr, "\t%.2f 		 		    %.2e\n", V, I);
    }

    if (knee_v != -1.0)
    {
        fprintf(ptr, "\nKnee Voltage: %.2f V(kenn v>0.3) \n", knee_v - 0.1);
    }
    else
    {
        fprintf(ptr, "Knee voltage doesn't exist in this range");
    }
    fclose(ptr);
}

void Germanium_diode_reverse()
{ // Variable declaration
    FILE *ptr = NULL;
    float q, k, T, V_t, I_s, I_knee_threshold, breakdown;

    // constants
    q = 1.6 * pow(10, -19); // Electron charge (C)
    k = 1.38e-23;           // Boltzmann constant (J/K)
    T = 298;                // Room temperature (K)
    V_t = (k * T) / q;      // Thermal voltage (V)
    I_s = 1e-9;             // Reverse saturation current (A)
    breakdown = 0;
    double V_b = -30; // we know it from physical tests

    // opening file
    ptr = fopen("Result(Ge-reverse).txt", "w");

    fprintf(ptr, "This is the result output of the Germanium (PN-Junction) DIODE:\nThese are the results of the behavior of the Germanium DIODE in reverse bias.\n\nTHEORY:\n🢧 We are using  Shockley diode equation mathematically describes how the current I through a PN junction diode depends on the applied voltage V across it.");
    fprintf(ptr, " \n🢧 Leakage current in a PN junction diode is the small reverse current that flows due to the movement of minority carriers when the diode is reverse biased. It remains nearly constant until the breakdown voltage is reached.");
    fprintf(ptr, "\n\nThe voltage is Input Voltage and the output is in the current");
    fprintf(ptr, "\n\tVoltage (Volt) \t Current (Amp)\n");

    for (float V = 0.0; V >= -30.0; V -= 5.0)
    {
        double I = -I_s;

        fprintf(ptr, "\t%.2f 		 		    %.2e\n", V, I);

        if (fabs(V) == fabs(V_b))
        {
            breakdown = V;
            fprintf(ptr, "\t%.2f 		 		    <<%.2e\n", V + (-5), I + I);
        }
    }
    fprintf(ptr, "\n\nBreakdown occurred at %.2f V\n", breakdown);

    fclose(ptr);
}
int main()
{
    int input, in2;
    printf("This program is for visualizing the forward and reverse bias conditions of a SILICON and GERMANUIM (PN-junction) diode.\nChoose Diode material\n");
recap:
    printf("1: Silicon \n2: Germanium\n3: Exit \n");
    scanf("\n%d", &input);
    switch (input)
    {
    case 1:
        printf("1: Forward Bias \n2: reversed bias\n3: Back to material \n");
        scanf("\n%d", &in2);
        switch (in2)
        {
        case 1:
            silicon_diode_foeward();
            break;

        case 2:
            silicon_diode_reverse();

            break;
        case 3:
            goto recap;
            break;
        default:
            printf("Invalid option!!\n Please choose again");
            break;
        }
        break;
    case 2:
        printf("1: Forward Bias \n2: reversed bias\n3: Back to material \n");
        scanf("\n%d", &in2);
        switch (in2)
        {
        case 1:
            Ge_diode_forward();
            break;

        case 2:
            Germanium_diode_reverse();

            break;
        case 3:
            goto recap;
            break;
        default:
            printf("Invalid option!!\n Please choose again");
            break;
        }
        break;
    }

    printf("\nResults are saved in files named by 'Result' \n");
    printf("________________________________________________________________________________________________________________________________");
    printf("\nProgram is created by- Rajat Uniyal\n");
    getch();
    return 0;
}