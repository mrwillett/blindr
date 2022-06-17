#ifndef BLINDR_H
#define BLINDR_H

#include "gnss.h"
#include "utils.h"
#include "stepper.h"
#include "toggle.h"
#include "solar.h"

#define MAX_CONSEC_CONN_FAILURES 3


void disable_all_interrupts_for(uint gpio);
void reenable_interrupts_for(uint gpio, int event);
void set_automation_state(uint *automation_enabled);
void normalize_boundaries(int *boundary_low, int *boundary_high, int *current_position);
void find_boundary(uint *low_boundary_set, uint *high_boundary_set, int *boundary_low,
                   int *boundary_high, int *current_position, uint gpio);
void toggle_callback(uint gpio, uint32_t event);
void handle_toggle(uint *low_boundary_set, uint *high_boundary_set, int *boundary_low,
                   int *boundary_high, int *current_position, uint *automation_enabled,
                   uint gpio, uint32_t event);
void enable_automation(uint *automation_enabled);
void disable_automation(uint *automation_enabled);
void read_actuate_alarm_sequence(int boundary_low, int boundary_high, int *current_position,
                                 int *event, uint automation_enabled, double *latitude,
                                 double *longitude, int *north, int *east, int *utc_offset,
                                 uint *baud_rate, uint new_baud, uint *gnss_configured, uint *config_gnss,
                                 uint *consec_conn_failures, uint *data_found, uint *time_only);
void actuate(int boundary_low, int boundary_high,
            int *current_position, int event, uint automation_enabled);
void alarm_callback(void);

#endif