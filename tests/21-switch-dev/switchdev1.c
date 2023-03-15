#include "contiki.h"
#include "net/netstack.h"
#include "contiki-conf.h"
#include "dev/radio.h"
#include "dev/leds.h"
#include "dev/cc2538-rf.h"
#include "dev/radio/cc1200/cc1200-const.h"
#include "dev/radio/cc1200/cc1200-conf.h"
#include "dev/radio/cc1200/cc1200-arch.h"
#include "dev/radio/cc1200/cc1200-rf-cfg.h"
#include "os/sys/clock.h"
#include "project-conf.h"

    
PROCESS(switch_radio_process, "Switch Radio Process");

AUTOSTART_PROCESSES(&switch_radio_process);

static struct etimer et;

PROCESS_THREAD(switch_radio_process, ev, data)
{
    PROCESS_BEGIN();

    while (1) {
        /* Toggle the LED to indicate which radio is currently active */
        if (NETSTACK_RADIO.get_value == NETSTACK_CONF_RADIO.get_value) {
            leds_on(LEDS_RED);
            leds_off(LEDS_GREEN);
        } 
        // else if (NETSTACK_RADIO.get_object == NETSTACK_CONF_RADIO_SUBGHZ.get_object) {
        //     leds_on(LEDS_GREEN);
        //     leds_off(LEDS_RED);
        // }

        // /* Wait for 5 seconds */
        // etimer_set(&et, CLOCK_SECOND * 5);
        // PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));

        // /* Switch to the other radio */
        // if (NETSTACK_RADIO.get_object == NETSTACK_CONF_RADIO.get_object) {
        //     NETSTACK_RADIO.set_object(NETSTACK_CONF_RADIO_SUBGHZ.get_object); 
        // } 
        // else if (NETSTACK_RADIO.get_object == NETSTACK_CONF_RADIO_SUBGHZ.get_object) {
        //     NETSTACK_RADIO.set_object(NETSTACK_CONF_RADIO.get_object);
        // }
    }

    PROCESS_END();
}
