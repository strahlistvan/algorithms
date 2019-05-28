class Party {
    partyName: string;
    voteCount: number;
    seatCount: number;
    proportionalSeats: number;

    constructor(name: string, votes: number) {
        this.partyName = name;
        this.voteCount = votes;
        this.seatCount = 0;
        this.proportionalSeats = 0;
    }
}

class Election {
    partyList: Party[];
    dHondtMatrix: number[][];
    mandateCount: number;
    method: (x: number) => number = (x: number) => x+1;
    treshold: number;

    private calcTotalVotes(): number {
        return this.partyList.map((p: Party) : number => p.voteCount)
                             .reduce( (sum, elem) => sum + elem);
    }

    private calcMatrix() {

        if (this.partyList.length > 0) {
            
            this.dHondtMatrix = [];
            
            for (let row = 0; row < this.mandateCount; ++row) {
                this.dHondtMatrix[row] = [];

                let divider = this.method(row);
                this.dHondtMatrix[row] = 
                    this.partyList.map( party => Math.floor(party.voteCount/divider) );
            }
        }  
    }

    private getNextMandateIndex() {
        let max: number = this.dHondtMatrix[0][0];
        let maxRowIndex: number = 0;
        let maxColIndex: number = 0;

        let totalVotes = this.calcTotalVotes()

        for (let rows = 0; rows < this.dHondtMatrix.length; ++rows) {

            for (let cols = 0; cols < this.dHondtMatrix[rows].length; ++cols) {

                if (!this.treshold || this.partyList[cols].voteCount > this.treshold * totalVotes ) {

                    if (this.dHondtMatrix[rows][cols] > max) {
                        maxRowIndex = rows;
                        maxColIndex = cols;
                        max = this.dHondtMatrix[rows][cols];
                    }
                }
            }
        }

        this.dHondtMatrix[maxRowIndex][maxColIndex] = null;

        return maxColIndex;
    }

    printMatrix() {
        if (!this.dHondtMatrix || this.dHondtMatrix.length === 0) {
            this.calcMatrix();
        }

        console.log(this.dHondtMatrix);
    }

    calcByPropotion() {
        let totalVotes = this.calcTotalVotes();

        this.partyList.forEach( 
            (p: Party) => p.proportionalSeats = this.mandateCount * (p.voteCount / totalVotes) 
        );
    }

    calcResult() {

        this.calcMatrix();

        for (let i=0; i<this.mandateCount; ++i) {
            let winnerIndex = this.getNextMandateIndex();
            ++this.partyList[winnerIndex].seatCount;
        }

        this.calcByPropotion();

        console.log(this.partyList);
        console.log(this.calcTotalVotes());
    }
}

let voteList: Party[] = [ new Party("Yellow", 47000) // {partyName: "Yelllow", voteCount: 47000} as Party
                         ,new Party("White", 16000) //{partyName: "White", voteCount: 16000} as Party
                         ,new Party("Red", 15900) // {partyName: "Red", voteCount: 15900} as Party
                         ,new Party("Green", 12000) //{partyName: "Green", voteCount: 12000} as Party
                         ,new Party("Blue", 6000) //{partyName: "Blue", voteCount: 6000} as Party 
                         ,new Party("Brown", 3100) //{partyName: "Brown", voteCount: 3100} as Party 
                        ];
 
let voteList2: Party[] = [ new Party("Yellow", 49000) 
                          ,new Party("White", 8000) 
                          ,new Party("Red", 13000) 
                          ,new Party("Green", 2000) 
                          ,new Party("Blue", 2000) 
                          ,new Party("Brown", 8000)
                          ,new Party("Black", 4500)
                          ,new Party("Pink", 4500)
                          ,new Party("Orange", 3500)
                          ,new Party("Cyan", 4000) 
                          ,new Party("Grey", 1500)
                       ];
                       
let election = new Election();
election.partyList = voteList2;
election.mandateCount = 10;
election.treshold = 0.05;
//election.method = (row: number) => Math.pow(2, row + 1);

election.calcResult();