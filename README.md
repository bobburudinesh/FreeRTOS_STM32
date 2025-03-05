---

# FreeRTOS on STM32

## Overview
This project demonstrates the integration of **FreeRTOS** with **STM32 microcontrollers**, focusing on real-time embedded systems. It covers essential **RTOS concepts** like **task management**, **inter-task synchronization**, **task scheduling**, **real-time debugging**, and more. The project also includes a practical implementation of a **menu-driven interface** with **LED control** and **RTC functionality** that is configurable by the user via **Tera Term**.

## Key Skills Demonstrated

### 1. **FreeRTOS Task Management**
   - **Task Creation, Deletion, and Scheduling**: Implemented dynamic creation and deletion of tasks with **different priorities** using FreeRTOS functions like `xTaskCreate` and `vTaskDelete`.
   - **Task Scheduling Policies**: Showcased different **scheduling policies** of FreeRTOS for real-time systems, such as round-robin and priority-based scheduling.
   - **Example**: 
     ```c
     xTaskCreate(taskFunction, "Task1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
     ```

### 2. **Inter-Task Synchronization with Semaphores, Mutexes, and Queues**
   - **Semaphores**: Used **binary semaphores** and **counting semaphores** to synchronize tasks and manage shared resources safely.
   - **Mutexes**: Applied **mutexes** to ensure mutual exclusion between tasks to avoid resource conflicts.
   - **Queues**: Implemented **queues** for safe and synchronized inter-task communication to pass data between tasks.
   - **Example**:
     ```c
     xSemaphoreTake(semaphoreHandle, portMAX_DELAY);
     xSemaphoreGive(semaphoreHandle);
     xQueueSend(queueHandle, &data, portMAX_DELAY);
     ```

### 3. **FreeRTOS Stack and Heap Management**
   - Managed **stack** and **heap memory** for task creation, ensuring efficient memory usage.
   - Configured **heap** and **stack** settings in FreeRTOS to avoid memory fragmentation and ensure system stability.

### 4. **Task Scheduling and Context Switching**
   - Implemented **context switching** to handle task execution efficiently, leveraging FreeRTOS's scheduling mechanism for real-time response.
   - Handled ARM Cortex-M specific code like `SVC_Handler`, `PendSV_Handler`, and `SysTick_Handler` for context switching and interrupt handling.
   - **Example**:  
     ```c
     #define configTICK_RATE_HZ 1000
     ```

### 5. **FreeRTOS Debugging with SEGGER SystemView**
   - Integrated **SEGGER SystemView** for real-time debugging and monitoring, enabling visualization of task execution and system performance.
   - Used **SystemView** to track FreeRTOS task states, interrupt handling, and task execution times for better debugging and optimization.

### 6. **LED Control and User Interaction via Tera Term**
   - Implemented a **menu-driven interface** allowing the user to select between **LED** and **RTC** functions.
   - **LED control**: Provided 4 different modes of operation for the LED, controlled by user input via **Tera Term**.
   - Demonstrated interaction between tasks and hardware peripherals in real-time using FreeRTOS.

   - Example:  
     ```c
     // Toggle LED based on user input
     if (user_input == LED_MODE_1) {
         HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);  // Toggle LED in mode 1
     }
     ```

### 7. **RTC Functionality (To Be Implemented)**
   - Displayed the **current date and time** and provided the user with the ability to **update the date and time**.
   - Framework set up for **RTC functionality**, with the full implementation to be added in the future.

   - Example:  
     ```c
     printf("Current Date and Time: %02d/%02d/%04d %02d:%02d:%02d", 
            current_day, current_month, current_year, current_hour, current_minute, current_second);
     ```

### 8. **FreeRTOS Kernel Configuration and Tick Timer**
   - Configured the **FreeRTOS kernel** for optimized task scheduling and real-time performance.
   - Set up the **kernel tick timer** to control task timing, using precise intervals for real-time task scheduling.

### 9. **Low Power Strategies in FreeRTOS**
   - Demonstrated the implementation of **low-power modes** by using **idle tasks** and **system ticks** to minimize power consumption while the system is not in active operation.

### 10. **Real-Time Embedded System Development**
   - Developed the system from scratch, applying **RTOS principles** such as **real-time task management**, **resource synchronization**, and **interrupt handling** to ensure optimal performance in embedded applications.

## Project Structure
```
FreeRTOS_STM32/
│
├── Src/                # Source files
│   ├── main.c          # Application code
│   ├── task.c          # FreeRTOS task management
│   ├── semaphore.c     # Semaphore handling
│   ├── queue.c         # Queue management
│   ├── led.c           # LED operations
│   ├── rtc.c           # RTC operations (to be implemented)
│
├── Inc/                # Header files
│   ├── task.h
│   ├── semaphore.h
│   ├── queue.h
│   ├── led.h
│   ├── rtc.h
│
├── FreeRTOS/           # FreeRTOS kernel files
│   ├── FreeRTOSConfig.h
│   ├── port.c          # Architecture-specific code (ARM Cortex-M)
│   ├── FreeRTOS.h
│
├── Debug/              # Debugging configurations
│   └── SystemViewConfig.h
│
├── .gitignore
├── README.md           # Project documentation
└── LICENSE             # Project license
```

## Key Features Implemented

- **Task Management**: Tasks are created, scheduled, and deleted using FreeRTOS, demonstrating task prioritization and scheduling.
- **Inter-Task Synchronization**: Used **semaphores**, **mutexes**, and **queues** to ensure safe communication and synchronization between tasks.
- **LED Control via User Input**: A menu-driven interface that lets users interact with LED behaviors in real-time, with 4 modes of operation.
- **RTC Functionality (Framework Set Up)**: RTC feature framework set up to display and update the current date and time (full implementation to be added).
- **FreeRTOS Debugging with SEGGER SystemView**: Integrated **SystemView** for real-time task execution visualization, helping with debugging and optimization.
- **Low Power Use Case**: Implemented **low-power modes** for efficient energy usage when the system is idle.
- **Context Switching**: Managed **context switching** using architecture-specific code, ensuring efficient task management on ARM Cortex-M.

## Future Enhancements
🚀 Completing **RTC functionality** for date and time updates  
🚀 Adding **DMA-based communication** for optimized data transfer  
🚀 Implementing **RTOS-based peripheral drivers** for STM32   
🚀 Exploring **advanced low-power techniques** in FreeRTOS

---

### Key Technologies:
- **FreeRTOS**
- **STM32 Microcontrollers**
- **Task Scheduling**
- **Semaphore, Mutex, and Queue Synchronization**
- **Real-Time Debugging with SEGGER SystemView**
- **LED and RTC Peripheral Control**
- **Low Power Modes in Embedded Systems**
- **C Programming for ARM Cortex-M**

---
