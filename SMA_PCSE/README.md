# Sistema de Monitoreo Ambiental
# Trabajo Final PCSE Co9 - Leandro Torrent
# El trabajo se complementa con el proyecto SMA de Miguel del Vall

# El sistema se encarga de sensar temperatura y porcentaje de humo del 
# ambiente y presenta informacion por UART y display OLED.

# Caracteristicas

Sistema Operativo: FreeRTOS
Hardware: EDU-CIAA
Sensores: AM2301 y MQ-2
Salidas: UART y Display OLED

# Tareas:

# am2301Task: Sensa datos de temperatura y envia a la tarea vReceiverTask.
# mq2Task: Sensa datos de porcentaje de humo en el ambiente y envia datos a la tarea vReceiverTask.
# vReceiverTask: Recibe datos de temperatura y porcentaje de humo y los muestra por UART y un Display Oled 128x64.


