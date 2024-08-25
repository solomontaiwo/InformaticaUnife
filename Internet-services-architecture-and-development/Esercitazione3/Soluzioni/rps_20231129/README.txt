In questo archivio ho inserito sia una soluzione con approccio "naive", basato
sull'assunzione che la prima read lato Server catturi interamente l'input
(opzione da passare a ps) del Client, che una soluzione con approccio
terminated data e riuso della socket. Come potete vedere la seconda soluzione è
significativamente più complessa, ma anche decisamente più robusta.
