#include <kipr/wombat.h>

#define ARM_LIFTED 800
#define TOP_HAT_THRESHOLD 3200
#define left 500
#define right 493

// Alternate code - doesn't work well
int other(){ 
    enable_servos();
    set_servo_position(0, 400);
    set_servo_position(3, 0);
    mav(0, left);
    mav(1, right);
    msleep(5000);
    
    mav(0, left);
    mav(1, right);
    while (digital(9)!=1){
        msleep(20);
    }
    mav(0,0);
    mav(1,0);
    msleep(100);
    set_servo_position(0, 0); 
    msleep(1000);
    set_servo_position(3, 1500);
    msleep(1000);
    set_servo_position(0, 400);
    msleep(1000);
    disable_servos();
    return 0;
}

int main(){
    wait_for_light(0);
    shut_down_in(120);
    
    enable_servos();
    set_servo_position(0, 400);
    set_servo_position(2, 0);
    msleep(3000);
    mav(0, left);
    mav(1, right);
    msleep(5000);
    mav(1, -right);
    msleep(2250);
    mav(0, -left);
    msleep(3000);
    mav(0, left);
    mav(1, right);
    while (digital(9)!=1){
        msleep(20);
    }
    mav(0,0);
    mav(1,0);
    msleep(100);
    set_servo_position(0, 0); 
    msleep(1000);
    set_servo_position(2, 1500);
    msleep(1000);
    set_servo_position(0, 400);
    msleep(1000);
    mav(0, -left);
    mav(1,-right);
    msleep(3000);
    set_servo_position(0, 0);
    mav(0,-left);
    mav(1,-right);
    msleep(30000);
    mav(0, left);
    mav(1, 0);
    msleep(5000);
    set_servo_position(0, 400);
    set_servo_position(2, 400);
    mav(0, -left);
    mav(1, -right);
    msleep(2000);
    disable_servos();
    return 0;
}
