/* 
 * Shawn Chin (STFC) 
 * Nov 2009
 */
#include "header.h"
#define PI 3.14159265358979323846

/* internal functions */
static double calculate_distance(double x1, double y1, double x2, double y2);
static double calculate_direction(double x1, double y1, double x2, double y2);
static double bounce(double xy, double wh);

int move_forward(void) {

    int my_id;
	double direction;
	double my_x, my_y;
	double vector_x, vector_y;
	
	/* retrieve my current location */
	my_x = get_x();
	my_y = get_y();
	my_id = get_id();
    direction = get_direction();

	/* movement in x and y directions */
	vector_x = cos(direction) * STEP_SIZE;
	vector_y = sin(direction) * STEP_SIZE;
	
	/* update position */
	my_x = my_x + vector_x;
	my_y = my_y + vector_y;

    /* if we hit the wall, bounce back */
    my_x = bounce(my_x, WIDTH);
    my_y = bounce(my_y, HEIGHT);
	
	/* post my location to board */
	add_location_message(my_id, my_x, my_y);
	
	/* write back to memory */
	set_x(my_x);
	set_y(my_y);
	
	/* still alive */
	return 0;
}

int change_direction(void) {
	
	int friend_1, friend_2;
	double my_x, my_y; /* my location */
	double f1_x, f1_y; /* location of friend 1 */
	double f2_x, f2_y; /* location of friend 2 */
    double direction, angle, distance;
	double dest_x, dest_y; /* where do I wish to go? */
	
	/* retrieve memory variables */
	my_x = get_x();
	my_y = get_y();
	friend_1 = get_friend_1();
	friend_2 = get_friend_2();
	
	/* read messages - get position of friends */
	START_LOCATION_MESSAGE_LOOP
		if (location_message->sender_id == friend_1)
		{
			f1_x = location_message->x;
			f1_y = location_message->y;
		}
		else if (location_message->sender_id == friend_2)
		{
			f2_x = location_message->x;
			f2_y = location_message->y;
		}
	FINISH_LOCATION_MESSAGE_LOOP
	
	/* RULE 1: Put F1 between us and F2 */
	/* Ideal way would be to calculate shortest path to vector originating 
	 * F1 and pointing away from F2.  
	 * Keep it simple for now. Head to where F1 would be right in the middle
     * of us and F2
	 */
	angle = calculate_direction(f2_x, f2_y, f1_x, f1_y); /* F2->F1 */
    distance = calculate_distance(f2_x, f2_y, f1_x, f1_y);
	dest_x = f1_x + (cos(angle) * distance);
	dest_y = f1_y + (sin(angle) * distance);

	/* RULE 2: Go between F1 and F2 */
	/* Ideal way would be to calculate shortest path to line between friends 
	 * Keep it simple for now. Try for midpoint between f1 and f2.
	 */
	//dest_x = (f1_x + f2_x) / 2;
	//dest_y = (f1_y + f2_y) / 2;
	

    /* calculate direction to destination */
    direction = calculate_direction(my_x, my_y, dest_x, dest_y);

    /* update my direction */
    set_direction(direction);
	
	/* still alive */
	return 0;
}

/* if point goes beyond wall, bounce back
 * xy = x or y coordinate
 * wh = width or height of bounding box
 */
static double bounce(double xy, double wh) {
    if (xy < 0) return (-xy);
    else if (xy > wh) return ((2 * wh) - xy);
    else return xy;
}

/* calculate angle of vector p1->p2 (in radians) */
static double calculate_direction(double x1, double y1, double x2, double y2) {
    return atan2((y2 - y1), (x2 - x1));
}

/* calculate distance between p1 and p2 */
static double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

