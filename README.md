# Master Thesis Work of MIKAEL LUCAS DE BRITO SOUSA

## TITLE: IMAGE-BASED GIMBAL ROBUST CONTROL FOR MULTI OBJECT TRACKING

======

## Advisors

* Academical Advisor: Prof. Dr. Flávio Luiz Cardoso Ribeiro
* Industrial Advisor: M.Eng. Raphael das Neves Calvo
* Extra Advisor: Dr. Luiz Gustavo Bizarro Mirisola (Committee Guest)

## Summary

This work aims to implement improvements in the 2DOF system equations of the gimbal system coupled with a planar camera, to provide a mathematical foundation to justify the control applied using PID techniques, to apply robust control techniques to improve simple PID control to ensure correct tracking within an acceptable margin (to be defined) of target/object movement, to implement a target identification algorithm to balance training classes using a large image dataset for training or augmentation data techniques applied for image context to ensure reliable accuracy in tracking of 2 or more targets within a system, and to provide reliable planar positioning for the application of projective geometry techniques for image processing and to improve target/object tracking similar to techniques used for precision robotic industrial manufacturing.

This work will be an evolution of the original work developed by Lucas Ávila on the topic "IMAGE-BASED GIMBAL CONTROL FOR OBJECT TRACKING".

## Milestones

* August, 10, 2026 - Planned date for sending the final version* of Qualification Text to the committee members. (3 weeks b.p.)
* September, 1, 2026 - Planned date for Qualification Presentation
* September, 16, 2026 - Limit date for Qualification Presentation
* July, 5, 2027 - Planned date for sending the Defense Text to the comittee members
* August, 2, 2027 - Planned date for Defense Presentation
* August, 16, 2027 - Limit date for Defense Presentation
* September, 16, 2027 - Limit date for Conclusion (corrections and publication by ITA's internal library)

*Plan to send first drafts of Qualification Text to my advisors between July 25th and August 3rd to evaluation.

## ABSTRACT

Image-based object tracking systems with Field-of-View (FoV) correction via rotating surfaces, such as gimbals, possess a solid mathematical foundation and are widely applied in both civil and military industries. However, integrating the components of such systems presents a series of challenges that demand both specific and systemic/generalist optimization solutions. Examples of this complexity include the systemic challenge of deployment on non-inertial platforms (subject to aerodynamic and vibrational disturbances) and the specific challenge of tracking and trajectory formation for multiple targets under severe hardware and processing constraints.

Recent literature have presented advancements in the systemic integration of vehicle tracking with gimbals on static bases, proposing control solutions for 2-DOF platforms in purely simulated environments. Despite these advancements, several operational and theoretical gaps persist—which will be detailed throughout this document—such as the need for deeper mathematical analysis of more robust control techniques, the optimization of classification algorithms, and the lack of Software-in-the-Loop (SIL) validations that operate the vision-estimation-communication pipeline using real images, moving beyond purely simulated scopes.

To address a portion of these limitations and advance the viable state-of-the-art, this qualification work proposes a strategy focused on three main pillars:

1. Dynamic Response Study and Optimization:
   In-depth analysis of control equations and the implementation of control loop corrections to ensure a fast transient response, allowing for precise trajectory tracking and the estimation of the tracked object's physical projection model.
2. Vision System Generalization and Validation:
   Evaluation and enhancement of tracking techniques (including multiple targets) through dataset balancing and the exploration of initial identification algorithms, aiming for greater system robustness against scenario variabilities and partial occlusions.
3. Software Simulation with Real Data:
   Implementation of a SIL test integrating the improved control with the tracking algorithm, utilizing real video inputs to validate the system's efficacy outside of purely simulated scenarios.

---

## CONFIGURATION AND PLANNING MANAGEMENT

### ITA SUMMARY

Summary made to enroll master's program at ITA:

"Sistemas de rastreio de alvos por imagem em bases estáticas possuem fundamentação matemática sólida; contudo, a aplicação em plataformas não-inerciais (como gimbals acoplados a veículos) eleva a complexidade devido à necessidade de integração entre a estabilização ativa e o controle de malha fechada. Este trabalho propõe uma estratégia de controle robusto focada em três pilares:
1- Otimização da Resposta Dinâmica: Implementação de correções na malha de controle para garantir uma resposta transitória rápida e com amortecimento crítico, permitindo o acompanhamento preciso de trajetórias.
2- Generalização do Sistema de Visão: Melhoria do algoritmo de rastreio através de técnicas de balanceamento de datasets, visando maior robustez da rede neural frente a variabilidades de cenário e oclusões parciais.
3- Compensação de Latência: Desenvolvimento de mecanismos para mitigar o atraso de transporte (latência de processamento), garantindo a sincronia entre a informação visual e a atuação eletromecânica."

### PEE SUMMARY

Summary made to registry on phase 3 of PEE:

"Desenvolver e implementar uma estratégia de controle robusto para um sistema de gimbal voltado ao rastreamento de alvos em tempo real. A pesquisa busca elevar o desempenho de soluções existentes através da mitigação crítica da latência de processamento e do refinamento dos modelos de visão computacional, utilizando para isso datasets mais balanceados e técnicas de equilíbrio por augmentation data models que garantam maior precisão em cenários variados. No âmbito do controle, o trabalho foca na estabilização em bases não inerciais, aplicando ferramentas analíticas de sistemas de controle para garantir a robustez e a estabilidade do rastreamento sob condições dinâmicas adversas.  "
