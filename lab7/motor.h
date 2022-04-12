#ifndef __LAB07_MOTOR_H_INCLUDED_
#define __LAB07_MOTOR_H_INCLUDED_

typedef enum {M_SLOW, M_MEDIUM, M_FAST} motor_speed_t;
typedef enum {M_BUSY, M_IDLE} motor_status_t;

void motor_init(void);
void motor_speed_limit(motor_speed_t speed);
void motor_move(uint32_t pos_in_tics);
uint32_t motor_get_position(void);
motor_status_t motor_status(void);

#endif
