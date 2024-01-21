# LineFollower 🏎 ... 🏁

This is a team project developed during a one-day hackathon, at the Introduction to Robotics course taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. The project consisted of assembling and programming a line follower robot.

## THE TEAM 👦🏻👩🏻‍🦱👩🏻
 
  Our team's name is ARC. The contributors of the project from this repository are:
  
   Alexandru Mihai (@AlexMihai1126 - https://github.com/AlexMihai1126)
   
   Cîrstea Ruxandra-Gabriela (@RuxiC - https://github.com/RuxiC)

   Ojoc Diana-Cristiana (@CristianaOD - https://github.com/CristianaOD)

## Project details

<details>
  <summary><h2><b>TASK REQUIREMENTS 📁</b></h2></summary>
  <h3>Functionality Requirements</h3>
  Assemble and program the improvised car to navigate a racetrack delineated by a looping black line, aiming for optimal speed and accuracy. The car must adhere to certain rules, including not taking shortcuts, staying on the track, and refraining from reversing on the track. The sole permitted movement is continuous progression along the black line. Utilize only six sensors from the QTR sensor array, and ensure that the sensor calibrates itself just before the robot commences its journey. Manual calibration of the sensor is not allowed, but as an added feature, the robot could employ calibration values stored in the EEPROM from previous calibration attempts. Additionally, the car chassis must be constructed by the team. Employ a PID controller and adjust its gains, specifically Kp, Ki (optional), and Kd, to define the characteristics of the robot's movement.

  <h3>Photo of the line follower kit with required components 📷</h3>
  <img src="https://github.com/RuxiC/LineFollower/blob/main/LineFollower/linefollower.png">

  <h3>Gradding details</h3>
  Grade (1-12 points):
  <ul>
    <li>< 20 seconds -> 10</li> < 20 seconds -> 10
    <li>> 35 seconds (but completed) -> 4.5 points</li>
    <li><=35 seconds: Between 10 and 5, the formula is as follows: time_score = 10 - 1/3 * (track_time - 20)</li>
  </ul>
</details> 

<details>
  <summary><h2><b>FUNCTIONALITY AND IMPLEMENTATION DETAILS 🔧</b></h2></summary> 
  <h3>Functionality:</h3>
  Initially, when positioned over the black line, the robot undergoes sensor calibration through iterative right movements. This process enables the robot to learn to identify the black line whenever it is detected in front of the sensor, while disregarding surfaces that are not the black line.
  
  <h3>Implementation:</h3>
  
  The PID algorithm: Initially, the PID controller's parameters were arbitrarily selected to observe the robot's behavior. Following many tests and an empirical approach, we decided on the gains kp = 9.7, ki = 0.0002, kd = 26.5.

  Calibration: We calibrated the robot by instructing it to rapidly move right for a specific duration within the "set" method of the code. The self-calibration method involved the robot moving to the right for 4 seconds, followed by a return to the initial position for black line detection.
  
  Our team's robot successfully completed the displayed racetrack in just 19.076 seconds!

   <h3>Chassis:</h3>
   
</details> 

<details>
  <summary><h2><b> COMPONENTS USED 🔌</b></h2></summary>
  
  <h3> Mechanical ⚙ </h3>
    <ul>
      <li>The chassis made out of foamboard (built by @AlexMihai1126 - https://github.com/AlexMihai1126)</li>
      <li>2x wheels</li>
      <li>1x ball caster</li>
      <li>Screws for the QTR-8A sensor</li>
      <li>2x 3D-printed DC Motor holders & appropriate screws</li>
    </ul> 
    
   <h3> Electronics ⚡ </h3>
    <ul>
      <li>1x Arduino Pro Micro </li>
      <li>1x Pololu QTR-8A reflectance sensor</li>
      <li>2x DC motors</li>
      <li>1x L293D motor driver</li>
      <li>1x LiPo battery for power</li>
      <li>1x mini-breadboard</li>
      <li>wires (as needed)</li>
      <li>1x Blue LED - for showing when we are in calibration mode</li>
      <li>1x 330 ohm resistor for the LED</li>
    </ul> 
</details>

<details>
  <summary><h2><b> SHOWCASE 📸 🎥</b></h2></summary>
  <details>
    <summary><h3><b> Racetrack Picture </b></h3></summary>
    <img src="https://github.com/RuxiC/LineFollower/blob/main/LineFollower/traseu.jpeg">
  </details> 
  <details>
    <summary><h3><b> Linefollower Setup Pictures </b></h3></summary>
    <img src="https://github.com/RuxiC/LineFollower/blob/main/LineFollower/line1.jpeg" alt="A photo of my setup" width="550" height="450">
    <img src="https://github.com/RuxiC/LineFollower/blob/main/LineFollower/line2.jpeg" alt="A photo of my setup1" width="550" height="450">
    <img src="https://github.com/RuxiC/LineFollower/blob/main/LineFollower/line3.jpeg" alt="A photo of my setup2" width="550" height="450">
   
  </details>

  ## You can see here a link to a video showcasing functionality 🎥
  https://youtu.be/3eNxRi1fzAw?si=j07vah7IKBF6WGvR
</details> 
