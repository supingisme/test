
/*_myown_start = .;*/
  .rongtao.init.func : { 
	/* . = ALIGN(4);*/	
	init_start = .;
	*(.rongtao.init.func*) 
	 init_end = .;
  }
/*  _myown_end = .;*/
