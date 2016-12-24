
<?php include ('common.php');?>

<!DOCTYPE html>
<html>
    <?php 
    	head();
    	banner();
    ?>
    
	<body>
	    
	    
		
		<form action="signup-submit.php" method="post">
		    <fieldset>
    		        <legend>New User Signup:</legend>
        		        <strong>Name:</strong><input type="text" name="name" required/> <br> <br>
        		        <strong>Gender:</strong><input type="radio" name="sex" value="M" checked="checked" required>Male <input type="radio" name="sex" value="F">Female<br> <br>
        		        <strong>Age:</strong><input type="text" name="age" size="6" required/> <br> <br>
        		        <strong>Personality type:</strong><input type="text" name="personality" size="6" required/> <span>(<a href="http://www.humanmetrics.com/cgi-win/JTypes2.asp">Don't know your type?</a>)</span> <br><br>
        		        <strong>Favorite OS:</strong><select name="os" required>
        		            <option name="Windows">Windows</option>
        		            <option name="Mac OSX">Mac OSX</option>
        		            <option name="Linux">Linux</option>
        		        </select> <br> <br>
        		        <strong>Seeking Age:</strong><input type="text" name="min" size="4" placeholder="min" required/> to <input type="text" name="max" size="4" placeholder="max" required/> <br> <br>
        		        <input type="submit" value="Sign Up"/>
		    </fieldset>
		</form>
		<?php
			foot();
		?>
		
        
    </body>
    
</html>