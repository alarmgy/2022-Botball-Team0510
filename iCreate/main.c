#include <kipr/wombat.h>

#define left 250
#define right 250

int main() {
    wait_for_light(0);
    shut_down_in(120);
    
    create_connect();
    create_start();
    enable_servo(3);
    set_servo_position(3, 400);
    create_drive_direct(left, -right);
    msleep(450);
    create_drive_direct(left, right);
    msleep(800);
    create_drive_direct(left*2, -right*2);
    msleep(500);
    create_drive_direct(-left*2, right*2);
    msleep(500);
    create_drive_direct(-left, -right);
    msleep(1300);
    create_drive_direct(0, 0);
    set_servo_position(3, 2200);
    msleep(15000);
    create_drive_direct(left, right);
    msleep(4000);
    create_drive_direct(left, -right);
    msleep(750);
    create_drive_direct(-left, -right);
    msleep(1800);
    create_drive_direct(left, right);
    msleep(4800);
    create_drive_direct(0, 0);
    msleep(1000);
    create_drive_direct(-left, right);
    msleep(2000);
    create_drive_direct(-left, -right);
    msleep(2000);

    return 0;
}
