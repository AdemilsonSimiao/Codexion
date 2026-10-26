codexion/
├── Makefile
├── include/
│   └── codexion.h          # structs e protótipos (um header só)
└── src/
    ├── main.c              # main
    ├── parsing/
    │   ├── validation.c    # negative_validacion, is_number, check_scheduler
    │   └── parse_args.c    # validate_args, fill_config
    ├── init/
    │   ├── init_data.c     # init_data (chama as outras)
    │   ├── init_dongles.c  # init_dongles, destroy_dongles
    │   └── init_coders.c   # init_coders
    ├── utils/
    │   ├── time.c          # get_time_ms, smart_sleep
    │   └── logger.c        # log_state
    ├── scheduler/
    │   ├── heap.c          # heap_push, heap_pop, swap, sift_up, sift_down
    │   ├── heap_utils.c    # heap_init, heap_destroy, heap_peek
    │   └── compare.c       # compare_fifo, compare_edf (com desempate)
    ├── dongle/
    │   ├── dongle_take.c   # request_dongle, wait_turn
    │   └── dongle_drop.c   # release_dongle, check_cooldown
    ├── coder/
    │   ├── coder_routine.c # coder_routine, one_cycle
    │   └── coder_actions.c # compile, debug, refactor
    ├── monitor/
    │   ├── monitor_routine.c  # monitor_routine
    │   └── monitor_checks.c   # check_burnout, check_all_done, stop_simulation
    └── cleanup/
        └── cleanup.c       # cleanup_all