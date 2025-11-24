def get_product_details(self, packageid, subversion=None):
        ret = None
        if packageid not in self.__products_cache:
            q = """SELECT id, name, """
            pm = self._product_cfgopt_map
            for k in pm:
                q += f'%s AS {k}, ' % pm[k]
            q += f"subdomain, paytype FROM tblproducts WHERE id = {packageid}"
            self.__db.execute(q)
            data = self.__db.fetchone()
            if data:
                all_opts = ('product', 'max_disk', 'sftp_access', 'sftp_access', 'max_bandwidth', 'ncpu',
                            'max_processes', 'io_limits', 'mail_limits', 'ssh_access', 'enable_uploads',
                            'enable_shell_exec', 'enable_sockets', 'enable_other_unsafe', 'create_google_apps',
                            'max_cronjobs', 'enable_alias', 'version', 'pmem', 'lve_package_name', 'sys_group_name',
                            'replication_cfg',
                            )
                for opt in all_opts:
                    if opt not in data:
                        data[opt] = None
                # Sanitizing output
                for v in data:
                    if data[v] == 'on':
                        data[v] = '1'
                    elif data[v] == 'off' or data[v] == '':
                        data[v] = '0'
                    if isinstance(data[v], str) and data[v].isdigit():
                        data[v] = int(data[v])
                try:
                    data['replication_cfg'] = json.loads(data['replication_cfg'])
                except Exception as e:
                    data['replication_cfg'] = {}
                self.__products_cache[packageid] = data
            ret = data
        else:
            ret = self.__products_cache[packageid]
        if subversion:
            ret['name'] += str(subversion)
        if not ret:
            raise Exception('There is no such productid: %d' % packageid)
        return ret