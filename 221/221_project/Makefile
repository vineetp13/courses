all: clean 
	$(MAKE) -C src/common ;							\
	$(MAKE) -C src/single_proc ;					\
	$(MAKE) -C src/process_context_switch ; 		\
	$(MAKE) -C src/pthread_context_switch ;			\
	$(MAKE) -C src/clone_context_switch ;			\
	$(MAKE) -C src/fork ;		  					\
	$(MAKE) -C src/pthread ; 						\
	$(MAKE) -C src/clone ;							\
	$(MAKE) -C src/page_fault ;				\
	$(MAKE) -C src/ram_latency ;
	$(MAKE) -C src/mem_bandwidth ;
	$(MAKE) -C src/fsread ;
	$(MAKE) -C src/3_file_cache_size ;
	$(MAKE) -C src/3_file_contention ;
	$(MAKE) -C src/network/roundtriptime ;
	$(MAKE) -C src/network/con_overhead_client ;
	$(MAKE) -C src/network/netbandwidth_client ;

clean:
	$(MAKE) -C src/common clean ;					\
	$(MAKE) -C src/single_proc clean ;				\
	$(MAKE) -C src/process_context_switch clean ;	\
	$(MAKE) -C src/pthread_context_switch clean ;	\
	$(MAKE) -C src/clone_context_switch clean ;		\
	$(MAKE) -C src/fork clean ;						\
	$(MAKE) -C src/pthread	clean ;					\
	$(MAKE) -C src/clone clean ;					\
	$(MAKE) -C src/page_fault clean ;			  \
	$(MAKE) -C src/ram_latency clean ;			  
	$(MAKE) -C src/mem_bandwidth clean ;
	$(MAKE) -C src/fsread clean ;
	$(MAKE) -C src/3_file_cache_size clean ;			  
	$(MAKE) -C src/3_file_contention clean ;
	
