<?php
    session_start();
    $username = $_SESSION["user"];
    $file = fopen("todo_".$username.".txt", "r");
    $dir = "todo_".$username.".txt";
    
    if($_POST["action"] == "add"){
        $text = $_POST["item"];
        $input = $text."\xA";
        file_put_contents("todo_".$username.".txt",$input, FILE_APPEND);
        header("Location: todolist.php");
    }
    
    else if($_POST["action"] == "delete"){
        $linenum = $_POST["index"];
        $count=1;
        while(!feof($file)){
            $line = fgets($file);
            if($count == $linenum){
                $contents = file_get_contents($dir);
                $contents = str_replace($line, '', $contents);
                file_put_contents($dir, $contents);
                header("Location: todolist.php");
            }
            $count++;
        }
    }
    
    fclose($file);
?>