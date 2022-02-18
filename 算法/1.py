锁 = 0

def api():
    while(锁):pass
    锁 = 1
    # 业务逻辑
    锁 = 0


