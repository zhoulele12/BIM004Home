## First Print
Rectangle length and width too big
Precision of 3D printer not enough to print 0.5mm teeth. Outer diameter too small (cannot fit into servo) Setting: 5.0mm inner, 6.0mm outer
Strength of knob seems good (wall thickness 0.8, infill density 15, nozzle size 0.25mm)
Outer ring is unnecessary

## Second Print
Knob strength lost. Wall thickness? Printer?
Outer diameter too big. Setting: 6.5mm inner, 8.5 outer

## Third Print - teeth only C12
Setting: 5.0mm inner, 7.5 outer. Barely fits in -> Just nice!

## Fourth Print C12
teeth less visible. Infill density different. (9% was good)
Tried to increase knob width. Still weak.

## Fifth Print-green C6
wall thickness 1.2mm Infill density 8%, 0.25mm nozzle size
teeth visible again. -> infill density seems to be the issue (As it turned out, not really).
knob strength still not good 

## Sixth Print-grey C14
wall thickness 1.2mm Infill density 5% -> strength restored
To further increase strength -> shorten knob

## Seventh Print orange B7
wall thickness 0.8mm Infill density 9% -> strength still there

## Eighth Print orange B7
wall thickness 0.8mm Infill density 5% -> strength still there

## Ninth Print
wall thickness 0.8mm Infill density 15% -> teeth retained -> **infill-density doesn't matter**

## Tenth Print
wall thickness 1.2mm Infill density 9% 

Tested all. Teeth seem to be a good fit already
Good setting at this point: infill density 9%, wall thickness 1.2mm, 0.25mm nozzle
Knob strength is the main bottle neck

## Modifications:
To further increase strength -> shorten knob, change shape to fit better (add circle, wider, longer)
decrease base height by 1mm.

After printing the same design with the same parameters at different printers, conclusion reached -> **PRINTER MATTERS**

## Circular Knob Design
B7 printer, wall thickness 1.2mmm, infill density 9% 
Strength increased massively with new design. 
Further steps to take: 
1. Further increase knob length, width, and circle diameter -> better fit
2. Tweak base height for larger friction
3. Curved surface for larger friction
4. Try thinner layers and higher infill density

## Tests
1. diameter 4.5, length 7.5, width 2.2
2. diameter 5, length 7.8, width 2.5 - X
3. diameter 5.5, length 8, wdith 2.7 - X	
4. diameter 4.7, length 7.7, width 2.4, base 4->5, knob 5->3 - X (knob too short, base still too short)
5. diameter 4.5, length 7.5, width 2.2, base 6, 7, 8, knob 5 - teeth magically fit better. 6 is the best. Knob can be enlarged.
6. diameter 4.75,5, length 7.5, width 2.5,(multiples of 0.25) base 6, knob 5 - diameter 5 is stuck in the hole. -> Let's use this!

## August 28th 2022
- Finished the code for new fingerprint lock, with a rocker switch
- Facing a few problems
1. Superglue not strong enough to hold servo. Solution: design a box and glue the box onto our door.
2. Reconsider fingerprint sensor location.
3. Strength of knob may be questionable. -> curved surface near where the knob connects the base.

## August 29th 2022
- Box 80% done
1. design screw holes using the the hole function in fusion. Figure out screw types.
2. ridges

print1, box bottom on B7
- pins can be longer - extended 2mm
- rectangular hole(17) move up - up by 5mm
- 2mm pilot hole was a brilliant guess! 
- move screw hole 8 down - 0.1mm
- screw hole 1 down - 0.1mm
- screw hole 6 right - 0.1mm
- hole 14 can be smaller - diameter decrease by 2mm
- length/width 16 can be smaller - both decrease by 0.5mm
- enlarged servo screw holes to 2.5mm to fit 2nd screw.

## August 30th 2022
- Modified design based on print1
- finished ridges
To-do
1. Check availability of screws - I have #3,4,6 
2. design screw holes using the the hole function in fusion. Figure out screw types.
3. Button hole.

print2, box bottom on B7
1. pin 4 too wide - diameter reduced by 0.2mm
2. screw hole 6 shift to the right - 0.1mm
3. screw hole 1 shift down - 0.1mm
4. move hole 5 up - 5mm
5. length width 16 can be further shortened - both decrease by 0.3mm
6. mid ridge of servo is blocking - 7*2*3mm cut
7. screw hole 8 down and right - 0.1mm
8. enlarge 2mm pilot holes by 0.2mm in diameter
9. enlarge 2.5 mm pilot holes by 0.2mm in diameter
- screw-related stuff - need to reconsider -> how to tap 3d printed material?
10. screws are too soft

print3, box bottom on B7
1. length width 16, just nice!
2. new gap just nice!
3. depth 15 need to be shortened. - 2mm
3. screw holes will be tested after arduino case recoverd and screws arrive.


print4, box top on B2
1. button hole can be slightly narrower - diameter -1mm
2. bottom two corners do not close. - widened entire ridge hole by 0.1mm

print5, box bottom on B7
1. depth 15 over-shortened - lengthen by 0.3mm
2. length 16 slight adjustment - shorten by 0.1mm
3. mid-ridge gaps shortened by 1mm


print6, box top on B2
1. button hole size good now!
2. ridge gap overly-widened - gap narrowed by 0.05mm -> the problem seems to be the corner

print8, box bottom on B7
1. depth 15 just nice!
2. length 16 just nice!
3. mid-ridge gaps just nice!

print9, box top on B7
1. ridge gap still needs to be narrowed. return to original.

After you finish, make a tolerance chart.

