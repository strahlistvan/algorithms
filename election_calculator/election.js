var Party = /** @class */ (function () {
    function Party(name, votes) {
        this.partyName = name;
        this.voteCount = votes;
        this.seatCount = 0;
        this.proportionalSeats = 0;
    }
    return Party;
}());
var Election = /** @class */ (function () {
    function Election() {
        this.method = function (x) { return x + 1; };
    }
    Election.prototype.calcTotalVotes = function () {
        return this.partyList.map(function (p) { return p.voteCount; })
            .reduce(function (sum, elem) { return sum + elem; });
    };
    Election.prototype.calcMatrix = function () {
        if (this.partyList.length > 0) {
            this.dHondtMatrix = [];
            var _loop_1 = function (row) {
                this_1.dHondtMatrix[row] = [];
                var divider = this_1.method(row);
                this_1.dHondtMatrix[row] =
                    this_1.partyList.map(function (party) { return Math.floor(party.voteCount / divider); });
            };
            var this_1 = this;
            for (var row = 0; row < this.mandateCount; ++row) {
                _loop_1(row);
            }
        }
    };
    Election.prototype.getNextMandateIndex = function () {
        var max = this.dHondtMatrix[0][0];
        var maxRowIndex = 0;
        var maxColIndex = 0;
        var totalVotes = this.calcTotalVotes();
        for (var rows = 0; rows < this.dHondtMatrix.length; ++rows) {
            for (var cols = 0; cols < this.dHondtMatrix[rows].length; ++cols) {
                if (!this.treshold || this.partyList[cols].voteCount > this.treshold * totalVotes) {
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
    };
    Election.prototype.printMatrix = function () {
        if (!this.dHondtMatrix || this.dHondtMatrix.length === 0) {
            this.calcMatrix();
        }
        console.log(this.dHondtMatrix);
    };
    Election.prototype.calcByPropotion = function () {
        var _this = this;
        var totalVotes = this.calcTotalVotes();
        this.partyList.forEach(function (p) { return p.proportionalSeats = _this.mandateCount * (p.voteCount / totalVotes); });
    };
    Election.prototype.calcResult = function () {
        this.calcMatrix();
        for (var i = 0; i < this.mandateCount; ++i) {
            var winnerIndex = this.getNextMandateIndex();
            ++this.partyList[winnerIndex].seatCount;
        }
        this.calcByPropotion();
        console.log(this.partyList);
        console.log(this.calcTotalVotes());
    };
    return Election;
}());
var voteList = [new Party("Yellow", 47000) // {partyName: "Yelllow", voteCount: 47000} as Party
    ,
    new Party("White", 16000) //{partyName: "White", voteCount: 16000} as Party
    ,
    new Party("Red", 15900) // {partyName: "Red", voteCount: 15900} as Party
    ,
    new Party("Green", 12000) //{partyName: "Green", voteCount: 12000} as Party
    ,
    new Party("Blue", 6000) //{partyName: "Blue", voteCount: 6000} as Party 
    ,
    new Party("Brown", 3100) //{partyName: "Brown", voteCount: 3100} as Party 
];
var voteList2 = [new Party("Yellow", 49000),
    new Party("White", 8000),
    new Party("Red", 13000),
    new Party("Green", 2000),
    new Party("Blue", 2000),
    new Party("Brown", 8000),
    new Party("Black", 4500),
    new Party("Pink", 4500),
    new Party("Orange", 3500),
    new Party("Cyan", 4000),
    new Party("Grey", 1500)
];
var election = new Election();
election.partyList = voteList2;
election.mandateCount = 10;
election.treshold = 0.05;
election.method = function (row) { return Math.pow(2, row + 1); };
election.calcResult();
