#include "EmergencyDecisionsFunctions.h"

void EngineTree(){
  char airborne = valid<char>("Are you airborne?");
  char overMountains, workingElectrical, engineRunning, temp, nightFlying, overWater, landingLight;
  
  switch (airborne){
		case 'n':
		case 'N':
			std::cout << "Have a drink and call a mechanic. \n";
			break;
		case 'y':
		case 'Y':
			workingElectrical = valid<char>("Is the electrial system working?");
			switch (workingElectrical){
				case 'y':
				case 'Y':
					engineRunning = valid<char>("Has the engine stopped running?");
					switch (engineRunning){
						case 'y':
						case 'Y':
							overMountains = valid<char>("Are you over the Mountains?");
							switch (overMountains){
								case 'y':
								case 'Y':
								nightFlying = valid<char>("Are you flying at night?");
								switch (nightFlying){
									case 'y':
									case 'Y':
										landingLight = valid <char>("Turn on the landing light and look out the window. \n Do you like what you see?");
										switch (landingLight){
											case 'y':
											case 'Y':
												std::cout << "Make emergency landing.\n";
												break;
											case 'n':
											case 'N':
												std::cout << "Turn off the landing light.\n";
												break;
										}
									case 'n':
									case 'N':
										std::cout << "Make emergency landing.";
										break;
								}
								case 'n':
								case 'N':
									overWater = valid<char>("Are you over water?");
									switch (overWater){
										case 'y':
										case 'Y':
											std::cout << "Inflate your life vest, make emergency landing. \n";
											break;
										case 'n':
										case 'N':
											std::cout << "Make emergency landing on a road. \n";
											break;
									}
							}
              break;
						case 'n':
						case 'N': 
						  temp = valid<char>("Is the outside air temperature < 32 degrees?");
							switch (temp){
								case 'y':
								case 'Y':
									std::cout << "Turn on the carburator heat. \n";
									break; 
								case 'n':
								case 'N':
									std::cout << "Switch to the other fuel tank. \n";
                  break;
							}
					}
          break;
				case 'n':
				case 'N':
					std::cout << "Turn on the master switch. \n";
					break;
        default:
          break;
			}
	}
}

void CommunicationsTree(){

}

void IcingTree(){

}
