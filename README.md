# PID_Controller_With_Dual_Temperature_Sensor

![WhatsApp Image 2023-07-10 at 6 09 25 PM](https://github.com/SawairaRafi/PID_Controller_With_Dual_Temperature_Sensor/assets/71180681/2f005e82-fdc0-4aaf-943f-4f7cfda61af3)

Expected Outcomes
1. The temperature control systems measure the box temperature in a sealed box.
2. Compare it to the setpoint and use a temperature sensor in a feedback loop to identify
errors.
3. The effort to correct the error, the heater or fan is turned ON/OFF depending on the
condition,
4. the heater is turned on if the current temperature is below setpoint, and the fan is turned
on if the current temperature is over setpoint.
5. By changes to the PID controller's 𝐾𝑝,𝐾𝑖, 𝑎𝑛𝑑 𝐾𝑑 values also affect the system's
overshoots, settling time, and rising time.

NOTE: The Code here is not Complete to get the Complete Code Go to my Pateron Page by clicking the sponsor button or by going to the url : https://www.patreon.com/SawairaRafi/



PID stands for (Proportional Integral Derivative). It is used to measure the difference between
the desired set point and the measured signal. In our project Temperature is the input signal, which
is constantly measured, and its difference is calculated with desired set point, which can be either
the room temperature or entered by the user.

Two objects of PID are created one is for fan which works in REVERSE direction and the other one is DIRECT direction which is used for
Filament bulb. myPID.Compute() is used to compute the PID value which is then used as a PWM for the fan and the Filament bulb. The PWM varies from 0 to 255

The dht.readTemperature() built infunction is used to get values from DHT11 and convert them in Celsius reading
