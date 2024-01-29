# Light-Intensity-Indicator-using-ADC-and-Microprocessor

Converts an analog signal from a photoresistor into a digital format using an Analog-to-Digital Converter (ADC0804), which is then fed into a uc32 microprocessor. Depending on light conditions, the photoresistor's resistance changes, creating a variable voltage input for the ADC. The uc32 interprets this digital signal and activates one of three LEDs (green, yellow, or red) to indicate light intensity (bright, regular, or dark). The LED status is determined through algorithms in the uc32 based on analog voltage readings.
