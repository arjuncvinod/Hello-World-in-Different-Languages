# Function to perform addition
add <- function(a, b) {
  return(a + b)
}

# Function to perform subtraction
subtract <- function(a, b) {
  return(a - b)
}

# Function to perform multiplication
multiply <- function(a, b) {
  return(a * b)
}

# Function to perform division
divide <- function(a, b) {
  if (b != 0) {
    return(a / b)
  } else {
    return("Error: Division by zero")
  }
}

# Function to calculate square root
sqrt_func <- function(a) {
  if (a >= 0) {
    return(sqrt(a))
  } else {
    return("Error: Square root of a negative number")
  }
}

# Function to calculate exponentiation
power <- function(base, exponent) {
  return(base ^ exponent)
}

# Main calculator loop
while (TRUE) {
  cat("Enter an operation (+, -, *, /, sqrt, ^) or 'q' to quit: ")
  operation <- readline()
  
  if (operation == "q") {
    cat("Calculator quitting. Goodbye!")
    break
  }
  
  if (operation %in% c("+", "-", "*", "/")) {
    cat("Enter the first number: ")
    num1 <- as.numeric(readline())
    cat("Enter the second number: ")
    num2 <- as.numeric(readline())
    
    if (operation == "+") {
      result <- add(num1, num2)
    } else if (operation == "-") {
      result <- subtract(num1, num2)
    } else if (operation == "*") {
      result <- multiply(num1, num2)
    } else {
      result <- divide(num1, num2)
    }
    
    cat("Result: ", result, "\n")
  } else if (operation == "sqrt") {
    cat("Enter a number: ")
    num <- as.numeric(readline())
    result <- sqrt_func(num)
    cat("Result: ", result, "\n")
  } else if (operation == "^") {
    cat("Enter the base: ")
    base <- as.numeric(readline())
    cat("Enter the exponent: ")
    exponent <- as.numeric(readline())
    result <- power(base, exponent)
    cat("Result: ", result, "\n")
  } else {
    cat("Invalid operation. Please try again.\n")
  }
}
