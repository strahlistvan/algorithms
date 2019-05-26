class Vote {
    partyName: string;
    voteCount: number;
    seatCount: number;
}

class Election {
    voteList: Vote[];
    dHondtMatrix: number[][];
    mandateCount: number;

    calcMatrix() {
        if (this.voteList.length > 0) {
            
            this.dHondtMatrix = [];
            
            for (let row = 0; row < this.mandateCount; ++row) {
                this.dHondtMatrix[row] = [];

                let divider = row + 1;
                this.dHondtMatrix[row] = 
                    this.voteList.map( val => Math.floor(val.voteCount/divider) );
            }
        }  
    }

    getNextMandateIndex() {
        let max: number = this.dHondtMatrix[0][0];
        let maxRowIndex: number = 0;
        let maxColIndex: number = 0;
    
        for (let rows = 0; rows < this.dHondtMatrix.length; ++rows) {

            for (let cols = 0; cols < this.dHondtMatrix[rows].length; ++cols) {
                if (this.dHondtMatrix[rows][cols] > max) {
                    maxRowIndex = rows;
                    maxColIndex = cols;
                    max = this.dHondtMatrix[rows][cols];
                }
            }
        }

        this.dHondtMatrix[maxRowIndex][maxColIndex] = null;

        return maxColIndex;
    }

    calcResult() {

        this.calcMatrix();

        for (let i=0; i<this.mandateCount; ++i) {
            let winnerIndex = this.getNextMandateIndex();
            ++this.voteList[winnerIndex].seatCount;
        }

        console.log(this.voteList);
    }
}

let voteList: Vote[] = [ {partyName: "Yelllow", voteCount: 47000, seatCount: 0}
                        ,{partyName: "White", voteCount: 16000, seatCount: 0}
                        ,{partyName: "Red", voteCount: 15900, seatCount: 0}
                        ,{partyName: "Green", voteCount: 12000, seatCount: 0}
                        ,{partyName: "Blue", voteCount: 6000, seatCount: 0}
                        ,{partyName: "Brown", voteCount: 3100, seatCount: 0} ];
                       
let election = new Election();
election.voteList = voteList;
election.mandateCount = 10;

election.calcResult();
console.log(election.dHondtMatrix);