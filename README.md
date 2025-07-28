# 🐙 Useless Box Mimic – (Group 15)

A playful, interactive "useless box" that looks and behaves like a little dungeon mimic. Built for the *Physical Computing* course at Politecnico di Milano, this project invites curiosity, encourages interaction, and rewards persistence with unexpected (and often grumpy) behavior.

## 🎯 Concept

The idea was to create a funny and engaging object that feels alive. At first, the box behaves shyly—retracting its limbs with hesitation—but as you keep interacting, it grows annoyed, and eventually angry. The three servo-powered arms act as expressive limbs, reacting to the user's insistence with gestures and timing that suggest personality.

The mimic box is designed to be simple to build, fun to play with, and easy to modify. You don’t need advanced electronics skills to get started—just curiosity and a little patience!

## 🧠 Features

- Three distinct interaction phases: **shy**, **annoyed**, and **angry**
- Multiple physical switches trigger the box’s behaviors
- LED light provides emotional feedback
- Modular, 3D-printable components
- Arduino-compatible and beginner-friendly

## 🧰 Components Used

| Component        | Quantity | Notes                                                   |
|------------------|----------|----------------------------------------------------------|
| Arduino Uno      | 1        | Or any compatible board                                  |
| MS18 Micro Servo | 4        | Small form factor to avoid internal collision            |
| 3-Leg Switch     | 3        | For user interaction                                     |
| Red LED          | 1        | Used for emotional feedback                              |
| White PLA        | –        | Used for all 3D printed parts                            |
| Touch Sensor     | 1 (opt.) | Optional, used for additional behavioral triggers        |
| 9V Battery       | 1 (opt.) | Optional power source for standalone operation           |

## 🎥 Demo

*Coming soon*

[![Mimic_demo]()]

## 🛠️ How It Works

1. The user presses a switch on the box.
2. The mimic opens slightly and shows hesitation (shy behavior).
3. With repeated presses, the arms become quicker and more aggressive.
4. Eventually, the box behaves angrily and attempts to "defend" itself.
5. LED feedback changes according to the emotional state.

All behaviors are handled in a single Arduino sketch (`Group_15.ino`) using basic timing, state transitions, and servo movements.


