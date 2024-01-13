import turtle

# Set up the turtle screen
window = turtle.Screen()
window.bgcolor("white")

# Create a turtle object
love_turtle = turtle.Turtle()
love_turtle.shape("turtle")
love_turtle.color("red")
love_turtle.speed(1)

# Draw a heart shape
love_turtle.begin_fill()
love_turtle.fillcolor("red")
love_turtle.left(140)
love_turtle.forward(183)
love_turtle.circle(-100, 200)
love_turtle.left(120)
love_turtle.circle(-100, 200)
love_turtle.forward(183)
love_turtle.end_fill()

# Display a message
love_turtle.penup()
love_turtle.goto(0, -50)
love_turtle.write("Will you be mine?", align="center", font=("Arial", 24, "bold"))

# Close the turtle graphics window on click
window.exitonclick()
