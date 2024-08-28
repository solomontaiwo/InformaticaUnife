<?php 

	include_once('connessione.php');

    $sql = "SELECT NUMERO_D, NOME_D FROM DIPARTIMENTO";
    
    $result = mysqli_query($link, $sql);
    
    $n_d = array();

    while ($row = mysqli_fetch_array($result)) {
		// $row => | NUMERO_D | NOME_D | ... |
		/* $row = [
			'NUMERO_D' => 4,
			'NOME_D' => 'Research',
		]*/
		
		$n_d [ $row['NUMERO_D'] ] = $row['NOME_D'];
		/* $n_d =[
				[4 => 'Research'],
				... 
			] */
    }
	    
    mysqli_close($link);
?>

<!DOCTYPE html>
<html lang="it">
    <head>
        <meta charset="utf-8">
		        
		<title>Esempio HTML + PHP</title>
		
		<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/water.css@2/out/water.css">

		<style>
			body {
				max-width: 1200px;
			}
		</style>
    </head>

    <body>
		<form action="insert.php" method="POST">
			<fieldset>
				<label>NOME_BATT:</label>
				<input type="text" name="NOME_BATT">
			</fieldset>
			<fieldset>
				<label>INIZ_INT:</label>
				<input type="text" name="INIZ_INT">
			</fieldset>
			<fieldset>
				<label>COGNOME:</label>
				<input type="text" name="COGNOME">
			</fieldset>
			<fieldset>
				<label>SSN:</label>
				<input type="text" name="SSN">
			</fieldset>
			<fieldset>
				<label>DATA_N:</label>
				<input type="text" name="DATA_N">
			</fieldset>
			<fieldset>
				<label>INDIRIZZO:</label>
				<input type="text" name="INDIRIZZO">
			</fieldset>
			<fieldset>
				<label>SESSO:</label>
				<input type="text" name="SESSO">
			</fieldset>
			<fieldset>
				<label>STIPENDIO:</label>
				<input type="number" name="STIPENDIO">
			</fieldset>
			<fieldset>
				<label>SUPER_SSN:</label>
				<input type="text" name="SUPER_SSN">
			</fieldset>
			<fieldset>
				<label>N_D:</label>
				<select name="N_D">
                    <?php foreach ($n_d as $index => $value): ?>
                        <option value="<?php echo $index; ?>"><?php echo $value; ?></option>	
					<?php endforeach; ?>
				</select>
			</fieldset>

			<input type="submit" value="Invia" />
		</form>
    </body>

</html>


