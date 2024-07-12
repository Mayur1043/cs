/* Interrupt handling using GPIO */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt
#define gpio_get_value
#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>       
#include <linux/kobject.h>   
#include <linux/interrupt.h>
		
// button related
static unsigned int gpioButton = 46; // P8_16
static unsigned int irqNumber;	     // mapped to gpioButton
static unsigned int numPresses = 0;
//static unsigned int value;
static unsigned int gpio_led1=60;
static unsigned int gpio_led2=44;
//static unsigned int var;
static irq_handler_t button_handler(unsigned int irq, void *dev_id, struct pt_regs *regs)
{
	//var = gpio_get_value(gpio_led1);
	if(gpio_get_value(numPresses) == 0)
	{	
		pr_info("Rising Edge\n");
   		gpio_set_value(gpio_led1,0);
   		gpio_set_value(gpio_led2,1);
   	}
   	else
   	{
   		pr_info("Falling edge\n");
   		gpio_set_value(gpio_led1,1);
   		gpio_set_value(gpio_led2,0);
   	}
   	//pr_info("Button press interrupt!\n");
   numPresses++;

   return (irq_handler_t) IRQ_HANDLED;
}

static int __init my_init(void){
   int result = 0;

   pr_info("Setting up IRQ for GPIO %d for button\n", gpioButton);

   if (!gpio_is_valid(gpioButton))
   {
      pr_err("Invalid GPIO for button!\n");
      return -ENODEV;
   }

   gpio_request(gpioButton, "sysfs");  
   gpio_direction_input(numPresses);  
   gpio_direction_output(gpio_led2,0);
   gpio_direction_output(gpio_led1,0);
   irqNumber = gpio_to_irq(gpioButton); 
   pr_info("GPIO %d mapped to IRQ number %d\n", gpioButton, irqNumber);

   gpio_export(gpioButton, false);  		// export in /sys/class/gpio/...
   gpio_export(gpio_led1, false);
   gpio_export(gpio_led2, false);
   result = request_irq(irqNumber, 
		   	(irq_handler_t) button_handler, 
			IRQF_TRIGGER_RISING || IRQF_TRIGGER_FALLING ,
			"my_button_handler",
			NULL);

   return result;
}

static void __exit my_exit(void)
{
   free_irq(irqNumber, NULL);
   gpio_unexport(gpioButton);                  
   gpio_free(gpioButton); 
   gpio_free(gpio_led1); 
   gpio_free(gpio_led2);                      
   pr_info("GPIO %d freed up\n", gpioButton);

   pr_info("%d button presses were detected!\n", numPresses);
   pr_info("Good bye from %s!\n", KBUILD_MODNAME);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("A simple interrupt driver using GPIO button");
