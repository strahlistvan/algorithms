package hu.simulator;

import java.util.*;

public class Simulation {
	List<Door> doorList = new ArrayList<Door>();
	
	public Simulation() {
		this.init(3);
	}
	
	public Simulation(Integer numberOfDoors) {
		this.init(numberOfDoors);
	}	
	
	public void init(Integer numberOfDoors) {
		for (int i=0; i<numberOfDoors; ++i) {
			doorList.add(new Door());
		}
		
		int r = (int) (Math.random()*doorList.size());
		doorList.get(r).setWinner(true);
	}
	
	public void playerSelectDoor() {
		int r = (int) (Math.random()*doorList.size());
		doorList.get(r).select();
	}
	
	public void MontyOpenDoors() {
		int openedDoorCount = 0;
		for (Door door: doorList) {
			if (!door.isSelected() && !door.isWinner()) {
				door.open();
				++openedDoorCount;
			}
			if (openedDoorCount == doorList.size() - 2) {
				break;
			}
		}
	}
	
	public void playerChangingDoor() {
		//select first closed door		
		for (Door door: doorList) {
			if (!door.isOpened() && !door.isSelected()) {
				door.select();
				door.open();
				break;
			}
		}
		//remove the previous selection
		for (Door door: doorList) {
			if (door.isSelected() && !door.isOpened()) {
				door.unselect();
			}
		}
	}
	
	public void printDoorList() {
		System.out.println(this.doorList);
	}
	
	public Integer getWinnerDoorIndex() {
		int i = 0;
		while (i < doorList.size() && !doorList.get(i).isWinner()) {
			++i;
		}
		return i;
	}

	public Integer getPlayersDoorIndex() {
		int i = 0;
		while (i < doorList.size() && !doorList.get(i).isSelected()) {
			++i;
		}
		return i;
	}	
	
	public Boolean isPlayerWins() {
		return this.getPlayersDoorIndex() == this.getWinnerDoorIndex();
	}
}
