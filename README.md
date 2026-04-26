# Electronic flower pot

I've decided to make an electronic flower pot: a device
that can keep irrigated a flower pot, given a water deposit
and a power source. 

**Some decisions**

  1) moisture sensor per pot: to water every plant 
  based on their needs
  2) water supply per pot: again, to water every plant 
  based on their needs. Another approach is to keep 
  a single pump and various valves, but it's more 
  complicated to coordinante
  3) configurable water schedule: because not every 
  plant needs the same
  4) (discarded by now) work only on schedule: to work 
  only when is daylight, for instance, to avoid make 
  noise at night

My idea is to develop a single device per flowerpot with
some DIP switch to configure how frequently the watering 
should be made. Every module is standalone: it has its 
own arduino nano, its own water pump, its own moisture 
sensor.... so it is easy to expand to new flower pots.

## The parts

As a brain, I will use an arduino uno. 

  * Water pump: 3.7V - 5V water pump [aliexpress](https://es.aliexpress.com/item/1005008648828231.html?spm=a2g0o.order_list.order_list_main.15.12ff1802vklrfd&gatewayAdapt=glo2esp)
  * Electric motor driver: TB6612FNG (módulo breakout). 

