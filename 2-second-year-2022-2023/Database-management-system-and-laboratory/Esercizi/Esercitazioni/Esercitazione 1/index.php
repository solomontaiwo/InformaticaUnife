<?php 

/* 
 * Costruisco un Array multidimensionale
 */

// Array di tutte le righe
$rows = array();

// Costruisco una per una tutte le righe ele inserisco nell'array $rows
// Prima riga
$data = array(
	'Nome' => 'Mario', 
	'Cognome' => 'Rossi', 
	'Salario' => '20.000');
	
array_push($rows, $data);

// Seconda riga
$data = [
		'Nome' => 'Alberto', 
		'Cognome' => 'Bianchi', 
		'Salario' => '21.000'
	];
	
array_push($rows, $data);

// Terza riga
$data = [
		'Nome' => 'Giulio', 
		'Cognome' => 'Neri', 
		'Salario' => '26.000'
	];
	
array_push($rows, $data);

?>

<!DOCTYPE html>
<html lang="it">
    <head>
        <meta charset="utf-8">
		<meta name="author" content="Giacomo Piva" />
        <meta name="description" content="Esempio 2">
		<meta name="keywords"  content="esempio html, esempio php" />		
        
		<title>Esempio PHP</title>
		
		<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/water.css@2/out/water.css">

		<style>
			body {
				max-width: 1200px;
			}
		</style>
    </head>
    
    <body>
		<h1>Esempio PHP</h1>
		
		<table>
			<thead>
				<tr>
					<th>Nome</th>
					<th>Cognome</th>
					<th>Salario</th>					
				</tr>
			</thead>
			<tbody>
				<?php foreach ($rows as $row): ?>
					<tr>
						<td class="col"><?php echo $row['Nome']; ?></td>
						<td><?php echo $row['Cognome']; ?></td>
						<td><?php echo $row['Salario']; ?></td>
					</tr>
				<?php endforeach; ?>				
			</tbody>
		</table>
		
	</body>
	
</html>


































