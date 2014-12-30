Light-Writer
a simple openFrameworks program that lets you Write with Light

original code Written By Patrick Long, updated by Synchronistic Savage of Open to Source
http://OpentoSource.net

tested on Ubuntu 12.04 64bit with openFrameworks 0.8.4
(if you have a 64bit linux system you may just be able to run the Bin File)

openFrameworks is required to compile; visit http://www.openframeworks.cc/ to download

if you need to change the camera input uncomment/set vidGrab.setDeviceID(1) with your cam number in place of the 1
you can also set the framerate if needed (i had to set my playstation eye to 50fps to work good)

Controls:::

, = retention up
. = retention down
f = fullscreen
v = Video settings (seems to do nothing on linux...think it should pull up a camera settings dialog on mac)
m = mirror toggle
n = flip toggle 

space = save image (images are saved to bin/data/captures/)
left mouse click = clear screen

q,w,e = RGB 1 up
a,s,d = RGB 1 down

t,w,u = RGB 2 up
g,h,j = RGB 2 down

TODO:::
figure out v4l2loopback output: was able to get OfxGstV4l2Sink to output straight cam image on OF 007 at full framerate, but when i tried to output the modded image (Light Writing) to loopback device the framerates were around 6fps...there has to be a way to do this with decent framerates, besides using ximagesrc in gstreamer...if you have any insight on this please let me know

thanks, and Enjoy


