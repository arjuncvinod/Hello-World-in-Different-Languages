fun main(args: Array<String>) {

	val m = checkMiladi(2021) 
    
    val h = checkHijri(1442)

    println(m) // false
    println(h) // true
}

fun checkMiladi(year: Int): Boolean {

	val yearType =
    	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
    		true // kabisat
    	} else {
    		false // basithoh
    	}
    
    return yearType
}

fun checkHijri(year: Int): Boolean {

	val arrayKabisat = arrayOf(2, 5, 7, 10, 13, 15, 18, 21, 24, 26, 29)

	val vrA = (year.toDouble() / 30).toInt()
    val vrB = vrA * 30
    val results = year - vrB
    
	val yearType =
    	if (results in arrayKabisat) {
        	true // kabisat
        } else {
        	false // basithoh
        }
        
    return yearType   
}

/*
Program to check the type of year (kabisat/bashitah), long/short year with koltin language.
*/
