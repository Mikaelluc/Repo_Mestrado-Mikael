# Master Thesis Work of Lucas Avila Silva
======

## Advisors
Marcos Maximo

Raphael das Neves Calvo

## Summary

Image-Based Gimbal Control using a Convolutional Neural Network 🚀
This repository presents the implementation of a real-time object tracking system for a Two-Degrees-of-Freedom (2-DOF) gimbal, developed as part of a Master's thesis. The project integrates advanced computer vision with robust control engineering to maintain a target object precisely centered within a camera's field of view.

Key Features & Technologies:
Object Detection: Utilizes YOLOv8 for state-of-the-art, real-time object localization in image frames.

State Estimation: Employs a Kalman Filter to effectively smooth noisy YOLOv8 measurements, estimate the object's true position and velocity, and mitigate data inconsistencies.

Gimbal Control: Implements a Proportional-Integral-Derivative (PID) controller to actuate the gimbal, ensuring stable and accurate camera orientation.

System Modeling: Features a detailed Simulink model of the 2-DOF gimbal, incorporating critical nonlinearities (e.g., friction) and communication delays (modeled via Padé approximation) for realistic simulation.

Real-time Performance: Validated in a real-time simulation environment, demonstrating the system's ability to handle latency and dynamic tracking challenges.

Objective:
The primary goal is to develop a comprehensive and robust control solution for image-based object tracking, crucial for applications in surveillance, autonomous systems, and aeronautical operations where precise target centralization is paramount.

## Milestones
September, 03 of 2024 - Qualification

August, 25 of 2025 - Dissertation Delivered to Jury Members

September, 05 of 2025 - Defense


## ABSTRACT

COPY N PASTE THE ABSTRACT FROM YOUR DISSERTATION HERE (WHEN AVAILABLE)
