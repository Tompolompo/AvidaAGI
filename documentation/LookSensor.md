INPUTS READ
Register Functions:
	1st register == habitat type sought
	2nd register == travel/sight distance sought
	3rd register == type of search
	4th register == resource/org id sought

Habitat
	0 == food
	1 == hills
	2 == walls  
	3 == hidden resources (hidden from a distance)
	4 == unhidden dens
	-2 == organisms
	fail if == 3 (hidden nests)
  
	-defaults dependent on organisms type
		-for pred, default habitat == -2 if invalid habitat input
		-for prey, default habitat == 0 if invalid habitat input

Distance
	-default to 1 if low invalid number (aka negative) input
	-default to half-log-axis-of-world if high number > half-long-axis 

Search Type
	-behavior dependent on habitat used
		-if habitat == 0 or 1 or 2 or 4: 
  			0 = look for closest edible res, closest hill/wall, or closest den (values >=1)
			1 = count # edible cells/walls/hills across entire distance used (values >=1)
			-1 = total value of resources of habitat used in cells across entire distance used

 		-if habitat == -2: 
  			0 = closest any org
			1 = closest predator
			2 = count predators
			-1 = closest prey
			-2 = count prey

		-default to 0 (closest) if invalid input

ID
	-find instances of resource with specified resource or org id
		-when searching for a specific organism, search type is ignored
	-when searching for a valid specific resource (food/hill/wall/den), the actual habitat type of that resource will be used instead of the input habitat type (if there is a mismatch)
	
	-default to -1 (no specific target / evaluate all instances of habitat sought) if invalid input
	

 
OUTPUTS WRITTEN
Register Functions:
	1st register == habitat used
	2nd register == travel/sight distance used
	3rd register == search type used
	4th register == resource / org id used
	5th register == count seen
	6th register == values seen 
	7th register == id seen
	8th register == org forage target seen

ITEM NOT SEEN (default register return values):
	1st register == habitat used
	2nd register == -1
	3rd register == search type used
	4th register == resource / org id used
	5th register == 0
	6th register == -9 
	7th register == -9
	8th register == -9

ITEM SEEN (overwriting/adding to defaults):
	2nd register == distance used or distance to first object matching search and habitat type
	5th register == count of organism or resource/hill/wall/den cells with value >=1
				-will be 1 if search type specified find nearest
				-will be 1 if looking for (and found) specific organism
	6th register == org current bonus for first organism (of correct type) seen 
			 or == summed value of all cells containing resource type searched for
	7th register == group id for first organism (of correct type) seen 
			 or == resource id of first resource of type searched for
	8th register == forage target for first organism (of correct type) seen


