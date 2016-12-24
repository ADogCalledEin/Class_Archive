<?php
    session_start();
    if(!(isset($_SESSION['user'])) && empty($_SESSION['user'])) {
        
        if(($_POST["name"] != "") && ($_POST["password"] != "")){
            $name = $_POST["name"];
            $password = $_POST["password"];
            
            //check if the user exists
            $users = fopen("users.txt", "r");
            $new = 0;
            while(!feof($users)){
                $line = fgets($users);
                $file_info = explode(":",$line);
                if($file_info[0] == trim($name)){
                    $new = 1;
                    $checking = $file_info;
                    break;
                }
            }
            if($new == 1){
                if(trim($checking[1]) == trim($password)){
                    $_SESSION["user"] = $name;
                    fclose($users);
                    $time = time()+3600*24*7;
                    setcookie("timestamp", date("D y M d, g:i:s a"), $time);
                    header("Location: todolist.php");
                }
                else{
                    $error = "The password does not match the username. Please try again";
                    echo $error;
                    $_SESSION['error'] = $error;
                    header("Location: start.php");
                }
            }
            else{
                if (!preg_match('~(?=.*[0-9a-z])^[a-z0-9]{3,8}$~',$name)){
                //if(!preg_match("/^[a-z0-9]{3,8}$/",$name)){
                    $error = "The user name should be lowercase letters and numbers between 3-8 characters.";
                    echo $error;
                    $_SESSION['error'] = $error;
                    header("Location: start.php");
                }
                else if(!is_numeric(substr($password,0,1))){
                    $error = "First charater of the password should be a number.";
                    echo $error;
                    $_SESSION['error'] = $error;
                    header("Location: start.php");
                }
                else if(!preg_match('~(?=.*[0-9a-z!@#$%^&amp;*()_+ ])^[a-z0-9!@#$%^&amp;*()_+ ]{5,11}$~',substr($password,0,-1))){
                    $error = "The password should contain lowercase leters and numbers only and should be 6-12 characters long.";
                    echo $error;
                    $_SESSION['error'] = $error;
                    header("Location: start.php");
                }
                else if((ctype_alpha(substr($password,-1))) || (ctype_digit(substr($password,-1)))){
                    $error = "The password should not end with a letter/number.";
                    echo $error;
                    $_SESSION['error'] = $error;
                    header("Location: start.php");
                }
                else{
                    $input = "\xA".$name.":".$password;
                    file_put_contents("users.txt",$input, FILE_APPEND);
                    $_SESSION["user"] = $name;
                    $time = time()+3600*24*7;
                    setcookie("timestamp", date("D y M d, g:i:s a"), $time);
                    header("Location: todolist.php");
                    fclose($users);
                }
            }
        }
        else{
            $error = "Username/Password was missing";
            $_SESSION['error'] = $error;
            header("Location: start.php");
        }
    }
    else{
        header("Location: todolist.php");
        fclose($users);
    }
    

?>