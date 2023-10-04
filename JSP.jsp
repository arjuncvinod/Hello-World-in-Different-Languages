<!DOCTYPE html>
<html>
<head>
    <title>Hello, World in JSP</title>
</head>
<body>
    <h1>Hello, World!</h1>
    <%
        // Java code embedded in JSP
        String message = "Hello, World!";
        out.println("<p>" + message + "</p>");
    %>
</body>
</html>
