package hu.simulator;

public class Main {

	public static Boolean gameSimulation(Integer doorCount) {
		
		Simulation sim = new Simulation(doorCount);
				
		sim.playerSelectDoor();
		//sim.printDoorList();
		sim.MontyOpenDoors();
		//sim.printDoorList();
		sim.playerChangingDoor();
		//sim.printDoorList();
		
		if(sim.isPlayerWins()) {
			System.out.println("Hoorray! Player wins the CAR!");
			return true;
		}
		System.out.println("Hoorray! Player wins a GOAT!");
		return false;
				
	}
	
	public static void main(String[] args) {
		
		Integer doorCount = args.length > 0 ? Integer.parseInt(args[0]) : 3;
		Integer testCount = args.length > 1 ? Integer.parseInt(args[1]) : 1000;
		System.out.println("Run " + testCount + " tests with "
				+  doorCount + "doors.");
		
		
		int winCount = 0;
		for (int i=0; i<testCount; ++i) {
			if (gameSimulation(doorCount)) {
				++winCount;
			}
		}
		System.out.println("Winning count: " + winCount 
		 + " winning percent: " + (double)winCount/testCount*100.0 + "%");

	}

}
