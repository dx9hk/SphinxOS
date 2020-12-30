global lgdt_func        ; load gd table

lgdt_func:
    lgdt [esp + 4] 
    ret


