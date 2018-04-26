describe("Champernowne constant digit finder function", function() {
  
  beforeEach(function() {
    this.constant = getChampernowneConstant(100);
	// alert(this.constant);
  });
  
  
  it("champernowneDigit(1)", function() {
    expect(champernowneDigit(1)).toBe(1);
  });
   
  it("champernowneDigit(2)", function() {
    expect(champernowneDigit(2)).toBe(2);
  });
   
  it("champernowneDigit(9)", function() {
    expect(champernowneDigit(9)).toBe(9);
  });
    
  it("champernowneDigit(10)", function() {
    expect(champernowneDigit(10)).toBe(1);
  });

  it("champernowneDigit(11)", function() {
    expect(champernowneDigit(11)).toBe(0);
  });

  it("champernowneDigit(12)", function() {
    expect(champernowneDigit(12)).toBe(1);
  });

  it("champernowneDigit(13)", function() {
    expect(champernowneDigit(13)).toBe(1);
  });

  it("champernowneDigit(14)", function() {
    expect(champernowneDigit(14)).toBe(1);
  });
  
  it("champernowneDigit(15)", function() {
    expect(champernowneDigit(15)).toBe(1);
  });


  it("champernowneDigit(19)", function() {
    expect(champernowneDigit(19)).toBe(4);
  });

 
/*
  for (var i=20; i<30; ++i) {
	(function f(i) {
	it("champernowneDigit("+i+")", function() {
		expect(champernowneDigit(i)).toBe(parseInt(this.constant[i-1]));
	  });
	  
	})(i);
  }
*/
  
 it("champernowneDigit(188)", function() {
    expect(champernowneDigit(188)).toBe(9);
  });
  
  
  it("champernowneDigit(189)", function() {
    expect(champernowneDigit(189)).toBe(9);
  });

  it("champernowneDigit(190)", function() {
    expect(champernowneDigit(190)).toBe(1);
  });
 
  it("champernowneDigit(191)", function() {
    expect(champernowneDigit(191)).toBe(0);
  });
  
    it("champernowneDigit(192)", function() {
    expect(champernowneDigit(192)).toBe(0);
  });
  
 
  /*
  it("champernowneDigit(191)", function() {
    expect(champernowneDigit(191)).toBe(0);
  });
  
  it("champernowneDigit(192)", function() {
    expect(champernowneDigit(192)).toBe(0);
  });
*/  
  it("champernowneDigit(8536013841772690)", function() {
	expect(champernowneDigit(8536013841772690)).toBe(9)
  });
  
});

/*

  Test.assertEquals(0, champernowneDigit(-1));
//  Test.assertEquals(1, champernowneDigit(2));
//  Test.assertEquals(8, champernowneDigit(9));
//  Test.assertEquals(9, champernowneDigit(10));
  Test.assertEquals(1, champernowneDigit(11));
  Test.assertEquals(0, champernowneDigit(12));
  Test.assertEquals(1, champernowneDigit(13));
  Test.assertEquals(1, champernowneDigit(14));
  Test.assertEquals(1, champernowneDigit(15));
  Test.assertEquals(2, champernowneDigit(16));
  Test.assertEquals(4, champernowneDigit(20)); 
  Test.assertEquals(9, champernowneDigit(8536013841772690));

  */