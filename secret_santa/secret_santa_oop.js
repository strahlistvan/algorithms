const EXP_COUNT = 1000;
const NUMBER_OF_PEOPLE = 3;

class MagicHat {
    constructor(size) {
        this.peopleInHat = Array(size).fill(0).map((val, idx) => idx + 1);
        this.shuffle();
    }
    shuffle() {
        for (let i = this.peopleInHat.length - 1; i > 0; --i) {
            let rand = Math.floor(Math.random() * (i + 1));
            [this.peopleInHat[i], this.peopleInHat[rand]] = [this.peopleInHat[rand], this.peopleInHat[i]];
        }
    }
    pick() {
        return this.peopleInHat.shift();
    }
    putBack(card) {
        this.peopleInHat.push(card);
    }
}

class Person {
    constructor(personId) {
        this.personId = personId;
        this.presentPersonId = null;
    }
    getRandomPersonFromHat(magicHat) {
        this.presentPersonId = magicHat.pick();
        if (this.presentPersonId === this.personId) {
            magicHat.putBack(this.presentPersonId);
            this.presentPersonId = magicHat.pick();
        }
        magicHat.shuffle();
    }
    toString() {
        return this.personId + " személy a " + this.presentPersonId + " személynek vesz ajándékot.";
    }
}

class Statistics {
    constructor(allExperiences, numberOfPeople) {
        this.allExperiences = allExperiences;
        this.numberOfPeople = numberOfPeople;
        this.createPresentMatrix();
        this.fillPresentMatrix();
    }
    createPresentMatrix() {
        this.presentMatrix = [];
        for(let i=0; i<this.numberOfPeople; i++) {
            this.presentMatrix[i] = [];
            for(let j=0; j<this.numberOfPeople; j++) {
                this.presentMatrix[i][j] = 0;
            }
        }
    }
    fillPresentMatrix() {
        this.allExperiences.forEach( exp => {
            exp.forEach( person => {
                let from = person.personId -1;
                let to   = person.presentPersonId -1;
                ++this.presentMatrix[from][to]
            });
        });
    }
    print() {
        console.log(this.allExperiences.length + " kísérlet során...");
        for (let i=0; i<this.presentMatrix.length; ++i) {
            for (let j=0; j<this.presentMatrix[i].length; ++j) {
                let percent = Math.round(100 * this.presentMatrix[i][j] / EXP_COUNT);
                console.log((i+1) + " ember a " + (j+1) + " embernek " + this.presentMatrix[i][j] + "-szer (" +
                    + percent + "%) adott ajándékot.");
            }
        }        
    }
}

let allExperiences = [];

for (let i=0; i<EXP_COUNT; ++i) {

    let magicHat = new MagicHat(NUMBER_OF_PEOPLE);    
    let peopleList = [];
    
    for (let currentPersonId = 1; currentPersonId <= NUMBER_OF_PEOPLE; ++currentPersonId) {
        let person = new Person(currentPersonId);
        person.getRandomPersonFromHat(magicHat);
        peopleList.push(person);
    }

    allExperiences.push(peopleList);
}

let stats = new Statistics(allExperiences, NUMBER_OF_PEOPLE);
stats.print();