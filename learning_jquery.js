**Learning jQuery**

Statement) jQuery is a fast, lightweight, and feature-rich JavaScript library designed to simplify the process of interacting with HTML documents and handling events. It provides a simple and concise syntax to select and manipulate HTML elements, making it easier to create interactive and dynamic web content.

Why is jQuery Needed?
Speaking simply, to make you code less and do more. Writing less code and doing more stuffs is always the intention of every coder, we are indeed lazy! That's a primary reason why you should learn jQuery.

Apart from that many codebases use jQuery, so to be able to understand and contribute to them this is something you should learn.

How to Include jQuery in a Project:
To use jQuery in your project, follow these steps:

Using a CDN: You can include jQuery using a Content Delivery Network (CDN) link. This allows you to use a hosted version of jQuery, which may provide benefits like caching and faster load times.

Head to this website https://releases.jquery.com/
Click on the latest version of the jQuery, you can click on any one, usually we use the minified version. Then copy and paste it at the very end of the Header section, a common practice is to add just after the title. We can just use the src part and ignore the integrity and crossorigin part.
Example using the Google CDN:

<!-- Add this to the <head> section of your HTML file -->
 <script src="https://code.jquery.com/jquery-3.7.0.min.js"></script>    
Check if jQuery is Ready: To ensure that your JavaScript code runs only after jQuery is fully loaded, use the $(document).ready() function (or the shorthand $(function() {})).

<script>
  $(document).ready(function() {
    // Your jQuery code goes here
    alert("HELLO WORLD! :)");
  });
</script>
Once jQuery is included, you can start using its functions and methods to interact with HTML elements, handle events, and create dynamic and engaging web content easily.

Task
Add the jQuery CDN to the HTML file in the header section.
Alert a Hello World message in the JavaScript file

--index.html = <!DOCTYPE html>
<html>
<head>
  <title>Simple jQuery Example</title>
  <!-- Include jQuery library from a CDN -->

</head>
<body>
  <h1 id="heading">Hello, jQuery!</h1>
  <p id="paragraph">This is a simple example to demonstrate jQuery.</p>
</body>
</html>

--index.js = $(document).ready(function() {
    // Your jQuery code goes here
    // alert a hello world message
});
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = index.html: HTML: 

<!DOCTYPE html>
<html>
<head>
  <title>Simple jQuery Example</title>
  <!-- Include jQuery library from a CDN -->
   <script src="https://code.jquery.com/jquery-3.7.0.min.js"></script>    

</head>
<body>
  <h1 id="heading">Hello, jQuery!</h1>
  <p id="paragraph">This is a simple example to demonstrate jQuery.</p>
</body>
</html>


JavaScript: 
$(document).ready(function() {
    // Your jQuery code goes here
    alert("HELLO WORLD! :)");
});

------------------------------Explanation:- 
HTML:

jQuery CDN: You've correctly added the link to the jQuery CDN within the <head> section of the HTML file. This ensures jQuery is available for your JavaScript code to use.
Title and Content: The HTML file includes a title and some basic content with element IDs for later manipulation.
JavaScript:

**<span class="math-inline">\(document\)\.ready\(\)\:** You've wrapped your alert message within the `(document).ready()` function. This ensures the code only runs after jQuery is fully loaded and ready.
Alert Message: The alert("HELLO WORLD! :)"); line displays the desired message when jQuery is available.
Overall, the solution successfully demonstrates including and using jQuery to display a simple message. 
