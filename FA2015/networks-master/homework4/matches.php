<?php include ('common.php'); ?>
<!DOCTYPE html>
<html>
    <?php 
        head();
        banner();
    ?>
    <body>
        <form action="matches-submit.php" method="get">
            <fieldset>
                <legend>Returning User:</legend>
                    <strong>Name:</strong><input type="text" name="name" required/> <br> <br>
                    <input type="submit" value="View My Matches"/>
            </fieldset>
        </form>
    </body>
    
    
    
    
    <?php
        foot();
    ?>
    
</html>