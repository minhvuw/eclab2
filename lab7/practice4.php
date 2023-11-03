<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Multiplication Table</title>
</head>
<body>

    <h2>Multiplication Table</h2>
    <form method="post">
        <label for="number">Enter a number:</label>
        <input type="number" name="number">
        <input type="submit" value="Generate Table">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $number = $_POST["number"];

        echo "<h3>Multiplication Table up to $number</h3>";
        echo "<table border='1'>";
        
        // Table header: Display column indices
        echo "<tr><th>&nbsp;</th>";
        for ($i = 1; $i <= $number; $i++) {
            echo "<th>$i</th>";
        }
        echo "</tr>";
        
        // Generate table rows
        for ($i = 1; $i <= $number; $i++) {
            echo "<tr><th>$i</th>"; // Row index

            // Generate multiplication table values
            for ($j = 1; $j <= $number; $j++) {
                echo "<td>" . ($i * $j) . "</td>"; // Multiplication results
            }
            echo "</tr>";
        }

        echo "</table>";
    }
    ?>
</body>
</html>