<?php 
    include ("common.php");
    $input = "\xA".$_POST["name"].",".$_POST["sex"].",".$_POST["age"].",".$_POST["personality"].",".$_POST["os"].",".$_POST["min"].",".$_POST["max"];
    file_put_contents("singles.txt", $input, FILE_APPEND);
?>

<!DOCTYPE html>
<html>
    <?php 
    	head(); 
    	banner();	
    ?>
	
		<div>
		    <strong>Thank you!</strong><br><br>
		    
		    Welcome to NerdLuv <?= $_POST["name"]?>!<br><br>
		    
		    Now <a href="matches.php">log in to see your matches!</a><br><br>
		    
		    
		</div>
		
		
		
		
		<?php
			foot();
		?>	
		
</html>