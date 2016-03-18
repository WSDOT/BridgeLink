Common Input Parameters {#common_input_parameters}
=======================
Station, offset, bearing, and angle are common input parameters used in many of the BridgeLink appliccations. These parameters can be input with simple decimal values or in common engineering format.

Notation
--------
The following notation is used to describe the common engineering format.

<table>
<tr><th>Symbol</th><th>Description</th><th>Example</th></tr>
<tr><td>|</td><td>Choose between pipe separated items</td><td>L|R<br>Choose "L" or "R"</td></tr>
<tr><td>[]</td><td>Items withing square brackets are optional</td><td>[+|-]<br>Use "+" or "-" or omit</td></tr>
<tr><td>x</td><td>Lowercase letters are digits 0-9</td><td>dd mm ss.ss<br>Angular measure as degree-minute-decimal seconds<br>45 22 34.22
</td></tr>
</table>


Stations
--------
Stations represent a position along an alignment. Stations can be input as a decimal number or as a number of full plus fractional chains.

<table>
<tr><th>Format</th><th>Examples</th></tr>
<tr><td>[+|-]dddd.dd</td><td>233.32<br>-89.92</td></tr>
<tr><td>US Units<br>[+|-]dd+dd.dd</td><td>2+33.32<br>-0+89.92</td></tr>
<tr><td>SI Units<br>[+|-]dd+ddd.dd</td><td>2+343.32<br>-0+894.92</td></tr>
</table>

Offsets
-------
Offsets represent a perpendicular distance measured from a reference line. Left and right orientation is based on the observer looking in the positive direction of the reference line. If the reference line is an alignment, left and right are based on the observer looking ahead on station.

<table>
<tr><th>Format</th><th>Examples</th></tr>
<tr><td>[+|-]dddd.dd<br>Values greater than zero are to the right of the reference line.</td><td>2343.32<br>-894.92</td></tr>
<tr><td>dddd.dd [L|R]</td><td>2343.32 R<br>894.92 L</td></tr>
</table>

Angles
------
Angles represent a departure from a reference line.

<table>
<tr><th>Format</th><th>Examples</th></tr>
<tr><td>[+|-]dddd.dd<br>Clockwise angles are positive.</td><td>45.32<br>-22.92</td></tr>
<tr><td>dddd.dd [L|R]<br>Angles to the right are clockwise</td><td>45.32 L<br>22.92 R</td></tr>
<tr><td>[+|-]dd [mm [ss.ss]]</td><td>45<br> 45 16<br>45 16 25.32<br>-32<br>-32 56<br>-32 56 14.56</td></tr>
<tr><td>dd [mm [ss.ss]] [L|R]</td><td>45 L<br> 45 16 L<br>45 16 25.32 L<br>32 R<br>32 56 R<br>32 56 14.56 R</td></tr>
</table>

Bearings
--------
Bearings represent the direction of a line in a Cartesian coordinate system.

<table>
<tr><th>Format</th><th>Examples</th></tr>
<tr><td>N|S dddd.dd [E|W]</td><td>N 34.23 E</td></tr>
<tr><td>N|S dd [mm [ss.ss]] E|W</td><td>S 34 W<br> S 34 15 W<br> S34 15 23.3 W</td></tr>
</table>
