package hu.simulator;

public class Door {
	private Boolean opened, selected, winner;

	Door() {
		this.opened = this.selected = this.winner = false;
	}

	public Boolean isOpened() {
		return opened;
	}

	public void open() {
		this.opened = true;
	}
	
	public void close() {
		this.opened = false;
	}

	public Boolean isSelected() {
		return selected;
	}

	public void select() {
		this.selected = true;
	}
	
	public void unselect() {
		this.selected = false;
	}

	public Boolean isWinner() {
		return winner;
	}

	public void setWinner(Boolean winner) {
		this.winner = winner;
	}
	
	@Override
	public String toString() {
		return "Door [opened=" + opened 
				+ ", selected=" + selected 
				+ ", winner=" + winner + "]";
	}
}
