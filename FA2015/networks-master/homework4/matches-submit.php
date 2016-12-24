<?php 
    include ('common.php'); 
    $input = $_GET["name"];
    $matches = array();
    $singles = file("singles.txt");
    foreach($singles as $single){
        list($name, $sex, $age, $type, $os, $min, $max) = explode(",", $single);
        $matches[$name]['name']=$name;
        $matches[$name]['sex']=$sex;
        $matches[$name]['age']=$age;
        $matches[$name]['type']=$type;
        $matches[$name]['os']=$os;
        $matches[$name]['min']=$min;
        $matches[$name]['max']=$max;
    }
    
    
?>
<!DOCTYPE html>
<html>
    <?php 
        head();
        banner();
    ?>
    <body>
        
    <?php
        if (!(array_key_exists($input, $matches))){
        echo '<strong>'.$input.'</strong> does not exist! <a href="signup.php">Sign up here!</a>';
        foot();
        return;
        }
    ?>
    <strong>Matches for <?= $input; ?> </strong>
    <div class="match">
        <?php
        
            foreach($matches as $match){
                $typeletters = similar_text($match["type"], $matches[$input]['type']);
                if ($match['sex'] != $matches[$input]['sex']){ 
                    if($match['age'] < $matches[$input]['max'] && $match['age'] > $matches[$input]['min'] ){
                        if($match['os'] == $matches[$input]['os']){
                            if($typeletters >= 2){
        ?>
                            
                            <p><?= $match['name']?>
                            <img src="https://webster.cs.washington.edu/images/nerdluv/user.jpg"/>
                            </p>
                            <ul>
                                <li><strong>Gender: </strong> <?= $match['sex'] ?></li>
                                <li><strong>Age: </strong>    <?= $match['age'] ?></li>
                                <li><strong>Type: </strong>   <?= $match['type'] ?></li>
                                <li><strong>OS: </strong>     <?= $match['os'] ?></li>
                            </ul>
                            <br><br><br><br><br><br><br>
                            
                                
                                
                                
                                
        <?php
          
                            }
                        }
                    }
                }
            }
        
        ?>
        
    </div>
    
    
    
    
    
    <?php
        foot();
    ?>
    </body>
</html>