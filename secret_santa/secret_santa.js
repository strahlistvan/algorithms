const EXP_COUNT = 1000;
const NUMBER_OF_PEOPLE = 3;

function swap(array, i, j) {
    let temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    return array;
}

/* Fischer-Yates / Knuth shuffle */
function shuffle(array) {
    for (let i = array.length - 1; i > 0; --i) {
        let rand = Math.floor(Math.random() * (i + 1));
        array = swap(array, i, rand);
    }
    return array;
}

function getRandomPresentList(NUMBER_OF_PEOPLE) {

    let peopleInHat = Array(NUMBER_OF_PEOPLE).fill(0).map((val, idx) => idx + 1);
    let peoplePresent = Array(NUMBER_OF_PEOPLE+1).fill(0);
    peopleInHat = shuffle(peopleInHat);
    
    for (let currentPerson = 1; currentPerson <= NUMBER_OF_PEOPLE; ++currentPerson) {
   
        //check if the people pulled himself
        if (peopleInHat[0] == currentPerson) {
            peopleInHat = swap(peopleInHat, 0, peopleInHat.length-1);            
        }
    
        //Insert the present list
        peoplePresent[currentPerson] = peopleInHat[0];
        //remove name from hat permanently
        peopleInHat.shift();
        
        shuffle(peopleInHat);
    }
    
    return peoplePresent;
}

function createMatrix(width, height) {
    let matrix = [];
    for(let i=0; i<height; i++) {
        matrix[i] = [];
        for(let j=0; j<width; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

function printText(presentMatrix, EXP_COUNT) {
    console.log(EXP_COUNT + " kísérlet során...");
    for (let i=1; i<presentMatrix.length; ++i) {
        for (let j=1; j<presentMatrix[i].length; ++j) {
            let percent = Math.round(100 * presentMatrix[i][j] / EXP_COUNT);
            console.log(i + " ember a " + j + " embernek " + presentMatrix[i][j] + "-szer (" + 
                + percent + "%) adott ajándékot.");
        }
    }
}

let allExperiences = [];
let presentMatrix = createMatrix(NUMBER_OF_PEOPLE+1, NUMBER_OF_PEOPLE+1);

for (let i=0; i<EXP_COUNT; ++i) {
    allExperiences.push(getRandomPresentList(NUMBER_OF_PEOPLE));
}

for (let i=0; i<allExperiences.length; ++i) {
    for (let j=1; j<=NUMBER_OF_PEOPLE; ++j) {
        ++presentMatrix[j][allExperiences[i][j]];
    }
}

console.log(presentMatrix);
printText(presentMatrix, EXP_COUNT);